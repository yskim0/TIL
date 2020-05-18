# sklearn.pipeline

## pipeline

- <전처리를 위한 변환기>
- 여러 변환 단계를 정확한 순서대로 실행할 수 있게 함.
- Pipeline은 연속된 단계를 나타내는 이름/추정기 쌍의 목록을 입력으로 받음.
- 마지막 단게에서는 변환기와 추정기를 모두 사용할 수 있고, 그 외에는 모두 변환기여야 함.
    - `fit_transform()` 메서드를 가지고 있어야 함.

- 파이프 라인의 `fit()` 메서드를 호출하면 모든 변환기의 `fit_transform()` 메서드를 순서대로 호출하면서 한 단계의 출력이 다음 단계의 입력으로 전달됨.
- 마지막 단계에서는 `fit()` 메서드만 호출함.

## 예제 코드

```python
from sklearn.pipeline import Pipeline
from sklearn.linear_model import LinearRegression

model = Pipeline([
    ('scaler', StandardScaler()),
    ('regressor', LinearRegression()),
])
```

```
파이프라인으로 결합된 모형은 원래의 모형이 가지는 fit, predict 메서드를 가지며 각 메서드가 호출되면 그에 따른 적절한 메서드를 파이프라인의 각 객체에 대해서 호출한다. 
예를 들어 파이프라인에 대해 fit 메서드를 호출하면 전처리 객체에는 fit_transform이 내부적으로 호출되고 분류 모형에서는 fit 메서드가 호출된다. 
파이프라인에 대해 predict 메서드를 호출하면 전처리 객체에는 transform이 내부적으로 호출되고 분류 모형에서는 predict 메서드가 호출된다.
```
