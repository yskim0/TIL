# ROUGE

Recall-Oriented Understudy for Gisting Evaluation (by Chin-Yew Lin)

- summarization 에서의 성능을 평가하기 위한 지표
- 모델이 생성한 summary와 reference를 대조하여 scoring
- precision, recall을 통해 구함.


## Recall

![recall](https://huffon.github.io/img/in-post/equation1.png)

- n-gram을 이용했을 때, 레퍼런스 안에서 모델이 생성한 서머리와 몇 개의 단어가 겹치는지

- 모델이 만든 서머리가 긴 문장이었을 경우 레퍼런스의 단어 대부분을 포함할 가능성이 높음.

--> **Precision의 필요성**

## Precision

![precision](https://huffon.github.io/img/in-post/equation3.png)

- 모델이 만든 서머리 중 레퍼런스와 몇 개의 단어가 겹치는지

- simple summary를 만들어야 할 경우 좋은 지표
- 그러나 레퍼런스 내의 불필요한 단어가 많은 경우, 좋은 점수를 받을 수 없음.


## Conclusion

- Precision, Recall을 모두 계산한 후 `F-Measure`를 측정해라


## Appendix

서머리의 일정 부분을 비교하는 성능 지표임.

### ROUGE-N 

- `ROUGE-1` : 레퍼런스와 모델 서머리 간 겹치는 unigram 수를 보는 지표
- `ROUGE-2` : 레퍼런스와 모델 서머리 간 겹치는 bigram 수를 보는 지표

```
Summary(by model):

the cat was found under the bed


Reference:

the cat was under the bed

--------------------------------------------

Summary(by model) (bigrams):

the cat, cat was, was found, found under, under the, the bed


Reference (bigrams):

the cat, cat was, was under, under the, the bed

```


### ROUGE-S

- Window Size가 주어졌을 때, 이 사이즈 내에 위치하는 단어쌍들을 묶어 해당 단어쌍들이 얼마나 중복되는지 측정

- `Skip-gram Co-ocurrence` 라고도 함.

```
WINDOW_SIZE = 2

Ex. cat in the hat
=> skip-bigram = {“cat in”, “cat the”, “cat hat”, “in the”, “in hat”, “the hat”}
```


### ROUGE-L

- Longest common subsequence(LCS)를 사용해 **최장 길이**로 매칭되는 문자열 측정.

```
Reference: police killed the gunman

Summary-1: police kill the gunman
Summary-2: the gunman kill police

-------
ROUGE-N: Summary-1 = Summary-2 (“police”, “the gunman”)
-------
ROUGE-L:
Summary-1 = 3/4 (“police the gunman”)
Summary-2 = 2/4 (“the gunman”)
```


# Reference

1. https://rxnlp.com/how-rouge-works-for-evaluation-of-summarization-tasks/#.XylWAeczZTZ

2. https://huffon.github.io/2019/12/07/rouge/
