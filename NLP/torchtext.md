**Field**
- `from torchtext import data`
- 앞으로 어떤 전처리를 할 것인지 미리 정의함
```
sequential : 시퀀스 데이터 여부. (True가 기본값)
use_vocab : 단어 집합을 만들 것인지 여부. (True가 기본값)
tokenize : 어떤 토큰화 함수를 사용할 것인지 지정. (string.split이 기본값)
lower : 영어 데이터를 전부 소문자화한다. (False가 기본값)
batch_first : 미니 배치 차원을 맨 앞으로 하여 데이터를 불러올 것인지 여부. (False가 기본값)
is_target : 레이블 데이터 여부. (False가 기본값)
fix_length : 최대 허용 길이. 이 길이에 맞춰서 패딩 작업(Padding)이 진행된다.
```
- [출처](https://wikidocs.net/60314)
- `build_vocab` 으로 vocab 생성할 수 있음
  ```py
  SRC.build_vocab(train_dataset, min_freq=2)
  TRG.build_vocab(train_dataset, min_freq=2)
  ```
 
