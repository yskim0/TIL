### 신경망과 딥러닝(2)
##### 벡터화
* Vectorization
    * 벡터화 : 코드에서 For문을 없애는 일종의 예술
    * non-vector : For문으로 인해 매우 복잡해지고 느림
    * vector : $ w^Tx $ 직접 계산 가능 
        * np.dot(w,x) + b
    * 실제 실행시간이 300배 이상 차이가 남. 
    이는 1분 걸릴 코드가 5시간 걸리는 사태가 일어날 수 있다는 것을 내포함.
    ***벡터화로 딥러닝을 구현하면 결과를 훨씬 빨리 얻을 수 있다*** 

    * numpy 라이브러리에서는 다양한 (벡터)함수를 가지고 있음
        * exp, log, abs, maximum, sum ... 
        * 따라서 For문을 쓰고 싶을 때 그 공식을 쓰지 말고, **넘파이 내장 함수를 쓸 수 있는지 먼저 확인** 하는 것이 중요

* Vectorizing Logistic Regression
    * $Z= np.dot(w^T,X)+b$
        * $Z^1$~$Z^m$까지를 포함하는 (1,m) 행렬이 됨
    * $db = \frac 1 m np.sum(dZ)$
    * $dw = \frac 1 m Xdz^T$
    * 이렇게 하면 for문 안 써도 됨.

* Implementing Logistic Regression
```
for iter in range(1000):
    Z = np.dot(w^T,X)+b
    A = sigmoid(Z)
    dz = A - Y
    dw = 1/m * np.sum(dZ)
    w := w - (learning rate) * dW
    b := b - (learning rate) * db
```


* Broadcasting in Python
    * sum 상황에서 axis 사용
        * axis = 0: 세로 축으로 더해라
        * axis = 1: 가로 축으로 더해라
    * reshape 함수는 호출 비용이 굉장히 저렴하므로 행렬의 차원을 확실하게 하는 것을 주저하지 말 것
    * 실수하지 않기 위해서는 rank=1인 것을 절대 쓰지 마라.
        * (5,1)같은 row/col. vector 만들 것
        * assert(a.shape==(5,1)) 
        매우 저렴하니 맘껏 쓸 것
        * rank = 1이라면 reshape함수를 써서라도 바꿔야 한다. 

* Neural Network
    * A : 활성값 의미. 신경망의 층들이 다음 층으로 전달해주는 값
    * 입력층은 X를 은닉층으로 전달
    a[0]는 입력층의 활성값
    * 신경망 층을 셀 때 입력층은 포함하지 않음

* Vectorizing Across Multiple Examples

![그림5](https://user-images.githubusercontent.com/48315997/72771538-8e3c9880-3c44-11ea-8914-339d1ad3e24d.png)



