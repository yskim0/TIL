## ML lec 02 - Linear Regression의 Hypothesis와 Cost


- 어떤 가설이 좋은가
    - 실제 데이터 값과 비교해서 얼마나 가까운지

`Cost(Loss) function`
- 실제 데이터 값과 거리를 측정함.
- 가설과 실제 데이터가 얼마나 다른지 계산
- 가장 간단한 방법은 `H(x)-y` 
    - 안좋음. +,-될 수 있기 때문
    - 그래서 제곱을 함. `(H(x)-y)^2`

$cost=\frac 1 m \sum (H(x^{(i)})-y^{(i)})^2$
$H(x) = Wx + b $

- 실제로는 W, b에 대한 function이 됨.
- 이 값(cost)를 작게 하는 것이 목적. 따라서 가장 작게 만드는 W, b를 구하는 것이 Linear Regression의 학습