import numpy as np
import pickle
import timeit

from konlpy.tag import Okt
from scipy.sparse import lil_matrix
from sklearn.naive_bayes import MultinomialNB
from sklearn.linear_model import LogisticRegression
# from sklearn.preprocessing import OneHotEncoder
"""
Req 1-1-1. 데이터 읽기
read_data(): 데이터를 읽어서 저장하는 함수
"""

# def read_data(filename):
#     file = open(filename, 'r', encoding='UTF-8')
#     ratings = []
#     file.readline().strip()
#     line = file.readline().strip()
#     while (line):
#         rating = line.split('\t');
#         ratings.append(rating)
#         line = file.readline().strip()
#     file.close()
#     return ratings

"""
Req 1-1-2. 토큰화 함수
tokenize(): 텍스트 데이터를 받아 KoNLPy의 okt 형태소 분석기로 토크나이징
"""

# def tokenize(do):
#     okt = Okt()
#     docs = []
#     for rating in do:
#         # tokens = []
#         token = okt.pos(phrase=rating[1], norm=True, stem=True)
#         # for tup in token:
#         #     type = tup[1]
#         #     if type in ['Noun', 'Adjective']:
#         #         tokens.append(tup[0]+"/"+tup[1])
#         # token = okt.nouns(phrase=rating[1])
#         docs.append([token, rating[2]])
#     return docs

"""
데이터 전 처리
"""

# # train, test 데이터 읽기
# print("read_data 시작")
# train_data = read_data('ratings_train.txt')
# test_data = read_data('ratings_test.txt')
#
# # Req 1-1-2. 문장 데이터 토큰화
# # train_docs, test_docs : 토큰화된 트레이닝, 테스트  문장에 label 정보를 추가한 list
# print("tokenize 시작")
# start = timeit.default_timer()
# train_docs = tokenize(train_data)
# test_docs = tokenize(test_data)
# stop = timeit.default_timer()
# print(stop - start)
#
# # Req 1-1-3. word_indices 초기화
# print("word_indices 생성 시작")
# word_indices = {}
#
# # Req 1-1-3. word_indices 채우기
# l = len(train_docs)
# i = 0
# for doc in train_docs:
#     for li in doc[0]:
#         word_indices.setdefault(li, len(word_indices))
#     i += 1
#     p = i / l * 100
#     if p % 5 == 0:
#         print(p, "%")
# # print("word_indices : ", word_indices)
# print("사전길이 : ", len(word_indices))
#
# # Req 1-1-4. sparse matrix 초기화
# # X: train feature data
# # X_test: test feature data
# # print("train_data.__len__():", train_data.__len__())
# # print("word_indices.__len__():", word_indices.__len__())
# X = lil_matrix((train_data.__len__(), word_indices.__len__()))
# X_test = lil_matrix((test_data.__len__(), word_indices.__len__()))
#
# # 평점 label 데이터가 저장될 Y 행렬 초기화
# # # Y: train data label
# # # Y_test: test data label
# Y = np.zeros(train_data.__len__())
# Y_test = np.zeros(test_data.__len__())
#
# # Req 1-1-5. one-hot 임베딩
# print("one-hot 임베딩 시작")
# # X,Y 벡터값 채우기
# okt = Okt()
# for idx, val in enumerate(train_docs):
#     Y[idx] = int(val[1])
#     for li in val[0]:
#         X[idx, word_indices.get(li)] = 1
# for idx, val in enumerate(test_docs):
#     Y_test[idx] = int(val[1])
#     for li in val[0]:
#         if li in word_indices:
#             X_test[idx, word_indices.get(li)] = 1
#
# print("data 파일 저장")
# with open('dataset.dat', 'wb') as f:
#     file = {'X': X, 'Y': Y, 'X_test': X_test, 'Y_test': Y_test}
#     pickle.dump(file, f)

pickle_obj = None
with open('dataset.dat', 'rb') as f:
    pickle_obj = pickle.load(f)
f.close()

X = pickle_obj['X']
X_test = pickle_obj['X_test']
Y = pickle_obj['Y']
Y_test = pickle_obj['Y_test']

# print("X : ", X)
# print("Y : ", Y)
# print("X_test : ", X_test)
# print("Y_test : ", Y_test)

# dictArr = np.asarray(word_indices.values()).reshape(-1, 1)
# enc = OneHotEncoder()
# enc.fit(dictArr)
# enc.transform([[문장]]).toArray()

"""
트레이닝 파트
clf  <- Naive baysian mdoel
clf2 <- Logistic regresion model
"""

# Req 1-2-1. Naive baysian mdoel 학습
# clf = MultinomialNB().fit(X, Y)

# Req 1-2-2. Logistic regresion mdoel 학습
clf2 = LogisticRegression().fit(X, Y)
print(clf2.coef_)
print(clf2.intercept_)

"""
테스트 파트
"""

# Req 1-3-1. 문장 데이터에 따른 예측된 분류값 출력
# print("Naive bayesian classifier example result: {}, {}".format(test_data[3][1], clf.predict(X_test)))
# print("Logistic regression example result: {}, {}".format(test_data[3][1], clf2.predict(X_test)))
print("Logistic regression example result: {}".format(clf2.predict(X_test)))

# Req 1-3-2. 정확도 출력
# print("Naive bayesian classifier accuracy: {}".format(clf.score(X_test, Y_test)))
print("Logistic regression accuracy: {}".format(clf2.score(X_test, Y_test)))

"""
데이터 저장 파트
"""

# Req 1-4. pickle로 학습된 모델 데이터 저장
# with open('model.clf', 'wb') as f:
#     filedict = {'clf': clf, 'clf2': clf2, 'word_indices': word_indices}
#     pickle.dump(filedict, f)
    
# Naive bayes classifier algorithm part
# 아래의 코드는 심화 과정이기에 사용하지 않는다면 주석 처리하고 실행합니다.
import math
"""
Naive_Bayes_Classifier 알고리즘 클래스입니다.
"""

class Naive_Bayes_Classifier(object):

    """
    Req 3-1-1.
    log_likelihoods_naivebayes():
    feature 데이터를 받아 label(class)값에 해당되는 likelihood 값들을
    naive한 방식으로 구하고 그 값의 log값을 리턴
    """
    
    def log_likelihoods_naivebayes(self, feature_vector, Class):
        log_likelihood = 0.0
        # feature_vector2 = np.absolute(feature_vector - 1)
        if Class == 0:
            log_likelihood += feature_vector.dot(self.likelihoods_0_1)
            # log_likelihood += feature_vector2.dot(self.likelihoods_0_0)
            # for feature_index in range(len(feature_vector)):
            #     if feature_vector[feature_index] == 1: #feature present
            #         log_likelihood += self.likelihoods_0_1.item(feature_index)
            #     elif feature_vector[feature_index] == 0: #feature absent
            #         log_likelihood += self.likelihoods_0_0.item(feature_index)
        elif Class == 1:
            log_likelihood += feature_vector.dot(self.likelihoods_1_1)
            # log_likelihood += feature_vector2.dot(self.likelihoods_1_0)
            # for feature_index in range(len(feature_vector)):
            #     if feature_vector[feature_index] == 1:
            #         log_likelihood += self.likelihoods_1_1.item(feature_index)
            #     elif feature_vector[feature_index] == 0:
            #         log_likelihood += self.likelihoods_1_0.item(feature_index)

        return log_likelihood
    """
    Req 3-1-2.
    class_posteriors():
    feature 데이터를 받아 label(class)값에 해당되는 posterior 값들을
    구하고 그 값의 log값을 리턴
    """
    
    def class_posteriors(self, feature_vector):
        log_likelihood_0 = self.log_likelihoods_naivebayes(feature_vector, 0)
        log_likelihood_1 = self.log_likelihoods_naivebayes(feature_vector, 1)

        log_posterior_0 = log_likelihood_0 + self.log_prior_0
        log_posterior_1 = log_likelihood_1 + self.log_prior_1

        return log_posterior_0, log_posterior_1

    """
    Req 3-1-3.
    classify():
    feature 데이터에 해당되는 posterir값들(class 개수)을 불러와 비교하여
    더 높은 확률을 갖는 class를 리턴
    """    

    def classify(self, feature_vector):
        log_posterior_0, log_posterior_1 = self.class_posteriors(feature_vector)
        return 0 if log_posterior_0 >= log_posterior_1 else 1

    """
    Req 3-1-4.
    train():
    트레이닝 데이터를 받아 학습하는 함수
    학습 후, 각 class에 해당하는 prior값과 likelihood값을 업데이트

    알고리즘 구성
    1) 가중치 값인 beta_x_i, beta_c_i 초기화
    2) Y label 데이터 reshape
    3) 가중치 업데이트 과정 (iters번 반복) 
    3-1) prediction 함수를 사용하여 error 계산
    3-2) gadient_beta 함수를 사용하여 가중치 값 업데이트
    4) 최적화 된 가중치 값들 리턴
       self.beta_x, self.beta_c
    """

    def train(self, X, Y):
        print("train 시작")
        start = timeit.default_timer()

        # label 0에 해당되는 데이터의 개수 값(num_0) 초기화
        num_0 = 0
        # label 1에 해당되는 데이터의 개수 값(num_1) 초기화
        num_1 = 0

        # Req 3-1-7. smoothing 조절
        # likelihood 확률이 0값을 갖는것을 피하기 위하여 smoothing 값 적용
        smoothing = 1

        # label 0에 해당되는 각 feature 성분의 개수값(num_token_0) 초기화
        num_token_0 = np.zeros((1, X.shape[1]))
        # label 1에 해당되는 각 feature 성분의 개수값(num_token_1) 초기화
        num_token_1 = np.zeros((1, X.shape[1]))
        
        # 데이터의 num_0,num_1,num_token_0,num_token_1 값 계산
        for i in range(X.shape[0]):
            if (Y[i] == 0):
                num_0 += 1
                num_token_0 += X[i]
        
            if (Y[i] == 1):
                num_1 += 1
                num_token_1 += X[i]
            # per = (i / X.shape[0] * 100)
            # if per % 10 == 0:
            #     print("진행율 ", per, "%")

        # smoothing을 사용하여 각 클래스에 해당되는 likelihood값 계산
        total_token_0 = 0
        for i in range(num_token_0.shape[1]):
            total_token_0 += num_token_0[0, i]
        self.likelihoods_0 = np.zeros((X.shape[1], 1))
        for i in range(num_token_0.shape[1]):
            self.likelihoods_0[i, 0] = (num_token_0[0, i] + smoothing) / total_token_0
        self.likelihoods_0_1 = np.log10(self.likelihoods_0)
        self.likelihoods_0_0 = np.log10(1 - self.likelihoods_0)

        total_token_1 = 0
        for i in range(num_token_1.shape[1]):
            total_token_1 += num_token_1[0, i]
        self.likelihoods_1 = np.zeros((X.shape[1], 1))
        for i in range(num_token_1.shape[1]):
            self.likelihoods_1[i, 0] = (num_token_1[0, i] + smoothing) / total_token_1
        self.likelihoods_1_1 = np.log10(self.likelihoods_1)
        self.likelihoods_1_0 = np.log10(1 - self.likelihoods_1)

        # 각 class의 prior를 계산
        prior_probability_0 = num_0 / len(Y)
        prior_probability_1 = num_1 / len(Y)

        # pior의 log값 계
        self.log_prior_0 = math.log(prior_probability_0)
        self.log_prior_1 = math.log(prior_probability_1)

        stop = timeit.default_timer()
        print("train time : ", stop - start)
        return None

    """
    Req 3-1-5.
    predict():
    테스트 데이터에 대해서 예측 label값을 출력해주는 함수
    """

    def predict(self, X_test):
        print("predict 시작")

        start = timeit.default_timer()

        predictions = []
        # X_test=X_test.toarray()
        length = X_test.shape[0]
        i = 0
        if (X_test.shape[0]==1):
            predictions.append(self.classify(X_test))
        else:
            for case in X_test:
                pred = self.classify(case)
                predictions.append(pred)
                # print("pred : ", pred, "Y_test", Y_test[i])
                # per = (i / length * 100)
                # if per % 1 == 0:
                #     print("진행율 ", per, "%")
                # i += 1

        stop = timeit.default_timer()
        print("predict time : ", stop - start)
        return predictions

    """
    Req 3-1-6.
    score():
    테스트를 데이터를 받아 예측된 데이터(predict 함수)와
    테스트 데이터의 label값을 비교하여 정확도를 계산
    """
    
    def score(self, X_test, Y_test):
        print("score 시작")
        predictions = self.predict(X_test)
        print("scoring 시작")
        correct = 0
        for i in range(len(Y_test)):
            if Y_test[i] == predictions[i]:
                correct += 1
        return correct / len(Y_test)

# Req 3-2-1. model에 Naive_Bayes_Classifier 클래스를 사용하여 학습합니다.
# model = Naive_Bayes_Classifier()
# model.train(X, Y)
# Req 3-2-2. 정확도 측정
# print("Naive_Bayes_Classifier accuracy: {}".format(model.score(X_test, Y_test)))

# Logistic regression algorithm part
# 아래의 코드는 심화 과정이기에 사용하지 않는다면 주석 처리하고 실행합니다.

"""
Logistic_Regression_Classifier 알고리즘 클래스입니다.
"""

class Logistic_Regression_Classifier(object):
    
    """
    Req 3-3-1.
    sigmoid():
    인풋값의 sigmoid 함수 값을 리턴
    """
    def sigmoid(self, z):
        # print("sigmoid")
        return 1/(1+math.e**-z)

    """
    Req 3-3-2.
    prediction():
    X 데이터와 beta값들을 받아서 예측 확률P(class=1)을 계산.
    X 행렬의 크기와 beta의 행렬 크기를 맞추어 계산.
    ex) sigmoid(            X           x(행렬곱)       beta_x.T    +   beta_c)       
                (데이터 수, feature 수)             (feature 수, 1)
    """

    def prediction(self, beta_x, beta_c, X):
        # print("prediction")
        # 예측 확률 P(class=1)을 계산하는 식을 만든다.
        return self.sigmoid(X.dot(beta_x) + beta_c)

    """
    Req 3-3-3.
    gradient_beta():
    beta값에 해당되는 gradient값을 계산하고 learning rate를 곱하여 출력.
    """
    
    def gradient_beta(self, X, error, lr):
        # print("gradient_beta")
        m = len(error)
        # beta_x를 업데이트하는 규칙을 정의한다.
        beta_x_delta = X.transpose().dot(error) / m * lr * 10
        # beta_c를 업데이트하는 규칙을 정의한다.
        beta_c_delta = sum(error) / m * lr
    
        return beta_x_delta, beta_c_delta

    """
    Req 3-3-4.
    train():
    Logistic Regression 학습을 위한 함수.
    학습데이터를 받아서 최적의 sigmoid 함수으로 근사하는 가중치 값을 리턴.

    알고리즘 구성
    1) 가중치 값인 beta_x_i, beta_c_i 초기화
    2) Y label 데이터 reshape
    3) 가중치 업데이트 과정 (iters번 반복) 
    3-1) prediction 함수를 사용하여 error 계산
    3-2) gadient_beta 함수를 사용하여 가중치 값 업데이트
    4) 최적화 된 가중치 값들 리턴
       self.beta_x, self.beta_c
    """
    
    def train(self, X, Y):
        print("train start")
        start = timeit.default_timer()

        # Req 3-3-8. learning rate 조절
        # 학습률(learning rate)를 설정한다.(권장: 1e-3 ~ 1e-6)
        lr = 1
        # 반복 횟수(iteration)를 설정한다.(자연수)
        iters = 400

        # beta_x, beta_c값을 업데이트 하기 위하여 beta_x_i, beta_c_i값을 초기화
        beta_x_i = np.zeros((X.shape[1], 1))
        beta_c_i = 0
        #행렬 계산을 위하여 Y데이터의 사이즈를 (len(Y),1)로 저장합니다.
        Y = Y.reshape(len(Y), 1)

        print("반복시작")
        for i in range(iters):
            #실제 값 Y와 예측 값의 차이를 계산하여 error를 정의합니다.
            error = self.prediction(beta_x_i, beta_c_i, X) - Y

            #gredient_beta함수를 통하여 델타값들을 업데이트 합니다.
            beta_x_delta, beta_c_delta = self.gradient_beta(X, error, lr)
            beta_x_i -= beta_x_delta
            beta_c_i -= beta_c_delta
            if i % 5 == 0:
                print("============== iters {} ===========", format(i))
                print("beta_x_i : ", beta_x_i)
                print("beta_c_i : ", beta_c_i)
        self.beta_x = beta_x_i
        self.beta_c = beta_c_i
        print("beta_x_i : ", beta_x_i)
        print("beta_c_i : ", beta_c_i)

        end = timeit.default_timer()
        print("train time : ", end-start)
        return None

    """
    Req 3-3-5.
    classify():
    확률값을 0.5 기준으로 큰 값은 1, 작은 값은 0으로 리턴
    """

    def classify(self, X_test):
        return 1 if self.prediction(self.beta_x, self.beta_c, X_test) > 0.5 else 0

    """
    Req 3-3-6.
    predict():
    테스트 데이터에 대해서 예측 label값을 출력해주는 함수
    """
    
    def predict(self, X_test):
        print("predict 시작")
        start = timeit.default_timer()
        
        predictions = []
        if (X_test.shape[0]==1):
            predictions.append(self.classify(X_test))
        else:
            for case in X_test:
                predictions.append(self.classify(case))
                
        stop = timeit.default_timer()
        print("predict time : ", stop - start)
        return predictions


    """
    Req 3-3-7.
    score():
    테스트를 데이터를 받아 예측된 데이터(predict 함수)와
    테스트 데이터의 label값을 비교하여 정확도를 계산
    """
    
    def score(self, X_test, Y_test):
        predictions = self.predict(X_test)
        correct = 0
        for i in range(len(Y_test)):
            if Y_test[i] == predictions[i]:
                correct += 1
        return correct / len(Y_test)

# Req 3-4-1. model2에 Logistic_Regression_Classifier 클래스를 사용하여 학습합니다.
model2 = Logistic_Regression_Classifier()
model2.train(X, Y)

# Req 3-4-2. 정확도 측정
print("Logistic_Regression_Classifier accuracy: {}".format(model2.score(X_test, Y_test)))

