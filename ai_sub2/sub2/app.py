import pickle
from threading import Thread
import sqlite3

import numpy as np
from konlpy.tag import Okt
from flask import Flask
from slack import WebClient
from slackeventsapi import SlackEventAdapter
from scipy.sparse import lil_matrix
from sklearn.naive_bayes import MultinomialNB
from sub2.service.MovieRatingService import MovieRatingService

import os

import db_init
import collections

# slack 연동 정보 입력 부분
SLACK_TOKEN = "xoxb-732130329415-726380228211-OyqL424g9slN9HViPpJUvR7S"
SLACK_SIGNING_SECRET = "cb5ad0ac62fc7dd14a577385e7637584"

app = Flask(__name__)

slack_events_adaptor = SlackEventAdapter(SLACK_SIGNING_SECRET, "/listening", app)
slack_web_client = WebClient(token=SLACK_TOKEN)

movieRatingService = MovieRatingService()

# Req 2-2-1. pickle로 저장된 model.clf 파일 불러오기
pickle_obj = None
word_indices = None
clf = None
clf2 = None

def loadModel():
    global pickle_obj, word_indices, clf, clf2

    with open('model.clf', 'rb') as f:
        pickle_obj = pickle.load(f)
    f.close()

    word_indices = pickle_obj['word_indices']

    clf = pickle_obj['clf']
    clf2 = pickle_obj['clf2']


# Req 2-2-2. 토큰화 및 one-hot 임베딩하는 전 처리
def preprocess(user_doc):
    okt = Okt()
    tokenized_doc = [word.rsplit('/', 1)[0] for word in okt.pos(user_doc.strip(), norm=True, join=True)]

    for word in tokenized_doc:
        check_word = word_indices.get(word)
        index_doc = []
        if check_word is not None:
            index_doc.append(check_word)

    sparse_matrix = lil_matrix((1, len(word_indices)))
    for idx in index_doc:
        sparse_matrix[0, idx] = 1

    return sparse_matrix

# Req 2-2-3. 긍정 혹은 부정으로 분류
def classify(sparse_matrix):

    return clf.predict(sparse_matrix.toarray())


# 챗봇이 멘션을 받았을 경우
@slack_events_adaptor.on("app_mention")
def app_mentioned(event_data):
    loadModel()

    channel = event_data["event"]["channel"]
    text = event_data["event"]["text"].split(' ', maxsplit=1)[1]

    if text is not None:
        data = movieRatingService.searchMovieRating(text)
        if data is None:
            preData = preprocess(text)

            label = classify(preData)[0]
            slack_web_client.chat_postMessage(
                channel=channel,
                text="{}".format("긍정적인 평가" if label == 1 else "부정적인 평가")
            )

            # Req 2-2-4. app.db 를 연동하여 웹에서 주고받는 데이터를 DB로 저장
            movieRatingService.insertMovieRating('user', text, label)
            clf.partial_fit(preData, [[label]])

            # with open('model.clf', 'wb') as f:
            #     filedict = {'clf': clf, 'clf2': clf2, 'word_indices': word_indices}
            #     pickle.dump(filedict, f)
        else:
            slack_web_client.chat_postMessage(
                channel=channel,
                text="{}".format("긍정적인 평가" if data[3] == 1 else "부정적인 평가")
            )

@app.route("/", methods=["GET"])
def index():
    return "<h1>Server is ready.</h1>"


if __name__ == '__main__':
    if not os.path.exists('app.db'):
        db_init.initMovieRatingDB()

    app.run(host='0.0.0.0', debug=True)
