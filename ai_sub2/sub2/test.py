import numpy as np
import pickle

from konlpy.tag import Okt
from scipy.sparse import lil_matrix
from sklearn.naive_bayes import MultinomialNB
from sklearn.linear_model import LogisticRegression
import collections
"""
test용입니다
Req 1-1-1. 데이터 읽기
read_data(): 데이터를 읽어서 저장하는 함수
"""

def read_data(filename):
    file = open(filename, 'r', encoding='UTF-8')
    ratings = []
    line = file.readline().strip()
    line = file.readline().strip()
    while (line):
        rating = line.split('\t');
        # 여기서 하고 싶은 일을 한다.
        ratings.append(rating)
        line = file.readline().strip()
    file.close()
    return ratings

"""
Req 1-1-2. 토큰화 함수
tokenize(): 텍스트 데이터를 받아 KoNLPy의 okt 형태소 분석기로 토크나이징
"""

def tokenize(doc):
    okt = Okt()
    tokens = []
    for rating in doc:
        token = okt.pos(phrase=rating[1])
        for tup in token:
            tokens.append(tup[0]+"/"+tup[1])
        # print(okt.pos(phrase=rating[1]))
    return tokens

"""
데이터 전 처리
"""

# train, test 데이터 읽기
train_data = read_data('ratings_ws.txt')
test_data = read_data('ratings_test.txt')

print("train_data : ", train_data)

# Req 1-1-2. 문장 데이터 토큰화
# train_docs, test_docs : 토큰화된 트레이닝, 테스트  문장에 label 정보를 추가한 list
train_docs = tokenize(train_data)
test_docs = tokenize(test_data)

print("train_docs : ", train_docs)

# Req 1-1-3. word_indices 초기화
word_indices = {}

# Req 1-1-3. word_indices 채우기
for doc in train_docs:
    list = doc.split('/')
    word_indices.setdefault(list[0], len(word_indices))

print("word_indices : ", word_indices)

# Req 1-1-4. sparse matrix 초기화
# X: train feature data
# X_test: test feature data
X = lil_matrix((train_data.__len__(), word_indices.__len__()))
X_test = lil_matrix((test_data.__len__(), word_indices.__len__()))

# 평점 label 데이터가 저장될 Y 행렬 초기화
# Y: train data label
# Y_test: test data label
Y = np.array(2)
Y_test = np.array(2)
