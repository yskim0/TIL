## reset_index

기존의 행 인덱스를 제거하고 인덱스를 데이터 열로 추가

In

```py
pd.DataFrame({'count' : meta.groupby(['role', 'level'])['role'].size()}).reset_index()
```

Out


|	|role|level|count|
|---|---|---|---|
|0|	id|	nominal|	1|
|1|	input|	binary|	17|
|2|	input|	interval|	10|
|3|	input|	nominal|	14|
|4|	input	|ordinal|	16|
|5|	target|	binary|	1|
