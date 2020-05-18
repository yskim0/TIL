## Bayesian-inference (베이지안 추론)

## 요약

**Bayesian Probability 베이지안 확률**
- "과거의 경험/정보로 부터 관심 있는 사건의 확률에 대해 추정한다."


![formula](https://t1.daumcdn.net/cfile/tistory/99552A435C05273631)


<br>

![generalized](https://t1.daumcdn.net/cfile/tistory/99D4FA415C0538A524)

위 식은 일어날 수 있는 사건들이 모두 **배반 사건**일 때 사용 가능함.

**Bayesian Inference 베이지안 추론**

- "추론 대상에 대한 사전분포를 알고, 데이터에 대한 적절한 가정(likelihood, f(x|θ))만 할 수 있다면, 우리는 이로부터 사후분포에 대해 추론할 수 있다."


- 모집단의 분포가 일정하지 않은 데이터들에 대해 다룸.

![infer1](https://t1.daumcdn.net/cfile/tistory/994CD94D5C34527825)

### Frequentism vs Bayesianism (빈도론 vs. 베이지안)

- 확률론 : "1000번을 던지면 166번, 10000번을 던지면 1666번 3이 등장한다."

- 베이지안 : "주사위를 던질 때, 3이 나온다고 1/6(16.66%) 확신할 수 있다."

- 즉, 빈도론 == '사건이 일어나는 장기적인 확률'. 경험적 사실만을 통해 이야기 할 수 있다는 객관적 입장

베이지안 == '지식이나 판단의 정도를 나타내는 수단'. 주관적 입장


### Bayesian Probability(베이지안 확률)

- 사전지식을 활용하여 우리가 알고싶은, 경험적으로 얻기 힘든 사건에 대해 확률을 추정하기 위해.

- 벤 다이어그램

**사건 A** : 경험적으로 알고 있는 사건
**사건 B** : 관심있는 사건

![img](https://t1.daumcdn.net/cfile/tistory/99FC784B5C053F170E)

![b1](https://t1.daumcdn.net/cfile/tistory/99099E495C053FA608)

![b2](https://t1.daumcdn.net/cfile/tistory/99822E505C05404103)

![ab](https://t1.daumcdn.net/cfile/tistory/99552A435C05273631)

- 용어

    - `P(A) / P(A1), P(A2), P(A3)`은 이미 알고 있는 정보, 알고있는 확률이라고 해서 사전확률(prior probability)이라고 함.
    - `B(B|A) / P(B|A1), P(B|A2), P(B|A3)`은 우도(likelihood)라고 함.
        - 과거의 경험에 근거하여 관심 있는 사건이 일어날 가능성
    - `P(A|B)`는 B라는 사건이 일어난 뒤에 그 것이 우리가 알고 있는 정보에 기인한 것인지를 알아보는 확률. 사후확률(posterior probability)라고 함.



### Bayesian Inference 베이지안 추론

베이지안 추론은 관측되지 않은 데이터들에 대해 다룸.
즉, **모집단의 분포가 일정하지 않음.**



- 추론 대상 : θ
- 추론 대상의 분포(사후 분포) : f(θ |x)
- 사전분포 : π(θ )

![infer](https://t1.daumcdn.net/cfile/tistory/994CD94D5C34527825)


* 추론 대상에 대한 사전분포를 알고, 데이터에 대한 적절한 가정(likelihood, f(x|θ))만 할 수 있다면, 우리는 이로부터 사후분포에 대해 추론할 수 있다.

**여기서 사후 분포가 어떤 성격을 갖도록 하느냐(특징을 정하느냐)는 이 θ 에 대해 어떤 추정량을 사용하느냐에 따라 달라짐.**

 1) 베이즈 추정량
  2) 사후 메디안 추정량
  3) MAP(Maximum a posterior) 추정량 

## Reference

[베이지안 추론(1) - 이론](https://sumniya.tistory.com/29)