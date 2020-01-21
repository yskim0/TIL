## 신경망과 딥러닝 

#####  Introduction

1. 

- 주택의 크기(X), 주택의 가격(Y) 예측 -> 신경망 가능
- Size => Node(Neuron) => Price
  중앙에 있는 뉴런들은 *은닉 유닛*
- **ReLU**(rectified Linear Unit)
- 사이즈 말고 다른 특성들이 있다고 가정.
  X = Size, Family size, Zip code, Wealth... 
  Y = Price 

2. **Supervised Learning**

   <img width="451" alt="image-20200120093257560" src="https://user-images.githubusercontent.com/48315997/72691587-cfac4580-3b69-11ea-8f74-f1c04b58fdb3.png">

   

- Image -> CNN
  Audio, Language -> 1차원 시계열 데이터로 나타내는 시퀀스 데이터 -> RNN

  자율주행, 레이더 -> 하이브리드 신경망 구조

- 구조적 데이터

  - 데이터베이스로 표현된 데이터
  - 광고 시스템이나 사용자 맞춤 추천에 적합

- 비구조적 데이터

  - 음성 파일, 이미지의 픽셀, 텍스트의 단어

3. Scale drives deep learning progress

   - 많은 양의 데이터를 이용하기 위해 충분히 큰 신경망 필요

   - 많은 양의 데이터 필요

   - 규모는 신경망의 크기 곧 많은 유닛, 많은 연결과 많은 파라미터를 가지는 것과 데이터의 규모

   - 가장 신뢰할 수 있는 방법 : 더 큰 신경망 훈련/더 큰 데이터
   - 레이블이 있는 데이터
   - 최근 몇 년간 알고리즘도 크게 발전 : 시그모이드 -> ReLU
   - 시그모이드 -> 함수의 경사가 거의 0인 곳에서 학습이 매우 느려짐
   - 신경망을 학습시키는 방법이 보통 반복적임
   - Idea -> Code ->Experiment

   

##### 신경망과 로지스틱 회귀

- Binary Classification

  - 입력된 사진을 나타내는 특성 벡터 x를 가지고 그에 대한 레이블 y가 **1아니면 0인지** 예측할 수 있는 분류 학습

  - (x, y) x in 
    $$
    R^{nx}
    $$
    space, y in {0,1}

    X.shape = (n,m)

    Y.shape = (1,m)

  - parameters : w in R^nx space, b in real numbers

  - Y = w^t * b?
    No!0~1사이의 값이 들어가야함
    -> Y의 값이 시그모이드 함수를 통과한 것
    Y = sigmoid(w^t * b)

  - Sigmoid = 1/ 1+e^(-z)

    - Z가 아주 크다면 1에 수렴
      	  아주 작다면 0에 수렴

  - Cost Function

    - Loss function : 제곱오차는 이진 분류에서 최적화되지 못함. (여러 개의 로컬 미니멈을 갖게 되어서)

      <img width="164" alt="image-20200120094615495" src="https://user-images.githubusercontent.com/48315997/72691568-bb684880-3b69-11ea-9d8b-1b5a614955fd.png">

    - Cost function : 훈련 세트 전체에 대해 얼마나 잘 추측되었는지 측정

    - 로지스틱 회귀 모델을 학습하는 것이란 손실 함수를 최소화 해주는 매개 변수 w와 b를 찾는 것

    <img src="https://user-images.githubusercontent.com/48315997/72691911-27e44700-3b6c-11ea-916d-476fe97cc2a8.png" alt="그림4" style="zoom:50%;" />

    

  - 경사하강법

    - 비용함수를 최소화하는 매개변수 w와 b를 학습시킴

    - Cost function은 convex 함수임

    - 비용 함수 J(w,b)가 볼록하다는 사실이 로지스틱 회귀에 사용한 큰 이유

      - W,b 어떤 초기값으로 초기화 해야함. 보통 0으로 사용. 무작위 초기값도 사용할 수 있지만 로지스틱 회귀에서는 안함.

    - Learning rate : 경사 하강법을 반복할 때 한 단계의 크기

      미분 계수 : 갱신할 때 매개변수 w에 줄 변화의 크기

      경사하강법에서는 큰 w를 선택한 다음에 서서히 매개변수를 감소시킴

    - $$
      w := w-\alpha \frac {df(x)} {dw}\\
      \\
      b := b-\alpha \frac {df(w)} {dw}
      $$

  - more derivative Ex.
    $$
    \frac d {da} f(a) = \frac 1 a
    $$

  - Computation Graph

    - 신경망의 계산 : 정방향 전파, 역전파

    

    <img src="https://user-images.githubusercontent.com/48315997/72691754-28c8a900-3b6b-11ea-8072-37d6ea581ab2.png" alt="그림1" style="zoom:50%;" />

    - 역전파

      - 마지막 출력값 변수의 v에 대한 도함수를 얻으면 그래프에서 한단계 뒤로 이동
      - 연쇄법칙

      $$
      dJdvar = \frac {dFindOutputVar.} {dvar.} = dvar
      $$

      <img src="https://user-images.githubusercontent.com/48315997/72691791-59a8de00-3b6b-11ea-91cd-f623f78f091b.png" alt="그림2" style="zoom:50%;" />

  - Logistic Regression Gradient Descent

    - 역전파의 마지막 단계는 w,b를 얼마나 바꿔야하는지 계산

  - Gradient Descenct on m Examples

    <img src="https://user-images.githubusercontent.com/48315997/72691810-852bc880-3b6b-11ea-8b49-f220caf32727.png" alt="그림3" style="zoom:50%;" />

    - 백터화 -> 명시적인 for문 제거 가능케 함.

