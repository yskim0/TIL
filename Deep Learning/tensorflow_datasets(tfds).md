# Tensorflow Datasets

- 텐서플로우에서 제공하는 데이터셋
- Train, Test를 split 하기 매우 편함.
- 모델 연습하기에 용이

## 라이브러리 설치

`pip install tensorflow-datasets`

```python
import tensorflow as tfdf
```

## Datasets 확인

```python
tfds.list_builders()
```

 ## Load Dataset



- tfdf.load()


```
split, (예 : 'train' , ['train', 'test'] , 'train[80%:]' , ...). 

shuffle_files,

data_dir, 데이터 세트가 저장된 위치 (기본값 ~/tensorflow_datasets/ )

with_info, : 데이터셋에 관련된 정보 O

download, : 사용 안 함 다운로드
```

 ```python
 train_data, test_data = tfds.load(
    name="cnn_dailymail", 
    split=(tfds.Split.TRAIN, tfds.Split.TEST),
    with_info=True)
```    

- cnn_dailymail 데이터셋을 다운하고, TRAIN, TEST셋 분할, info 보겠다.

- `info`

```
tfds.core.DatasetInfo(
    name='cnn_dailymail',
    version=3.0.0,
    description='CNN/DailyMail non-anonymized summarization dataset.

There are two features:
  - article: text of news article, used as the document to be summarized
  - highlights: joined text of highlights with <s> and </s> around each
    highlight, which is the target summary
',
    homepage='https://github.com/abisee/cnn-dailymail',
    features=FeaturesDict({
        'article': Text(shape=(), dtype=tf.string),
        'highlights': Text(shape=(), dtype=tf.string),
    }),
    total_num_examples=311971,
    splits={
        'test': 11490,
        'train': 287113,
        'validation': 13368,
    },
    supervised_keys=('article', 'highlights'),
    citation="""@article{DBLP:journals/corr/SeeLM17,
      author    = {Abigail See and
                   Peter J. Liu and
                   Christopher D. Manning},
      title     = {Get To The Point: Summarization with Pointer-Generator Networks},
      journal   = {CoRR},
      volume    = {abs/1704.04368},
      year      = {2017},
      url       = {http://arxiv.org/abs/1704.04368},
      archivePrefix = {arXiv},
      eprint    = {1704.04368},
      timestamp = {Mon, 13 Aug 2018 16:46:08 +0200},
      biburl    = {https://dblp.org/rec/bib/journals/corr/SeeLM17},
      bibsource = {dblp computer science bibliography, https://dblp.org}
    }
    
    @inproceedings{hermann2015teaching,
      title={Teaching machines to read and comprehend},
      author={Hermann, Karl Moritz and Kocisky, Tomas and Grefenstette, Edward and Espeholt, Lasse and Kay, Will and Suleyman, Mustafa and Blunsom, Phil},
      booktitle={Advances in neural information processing systems},
      pages={1693--1701},
      year={2015}
    }""",
    redistribution_info=,
)
```

## 데이터 가져오기

`tf.data.Dataset` 클래스에서 데이터를 가져오려면 `batch()` 메서드를 이용해서 한 번에 가져올 데이터 수를 정하고 `iter()` 함수로 이터레이터를 만들어 데이터를 가져옴.

> 예시

```python
data = []
iterator = iter(train_data.batch(2))
data.append(next(iterator))
data.append(next(iterator))
data.append(next(iterator))
```

```
data[0].keys()

> dict_keys(['article', 'highlights'])
```

```
data[0]["article"].shape

> TensorShape([2])
```

```
data[0]["article"]

> <tf.Tensor: shape=(2,), dtype=string, numpy=
array([b"By . Associated Press . PUBLISHED: . 14:11 EST, 25 October 2013 . | . UPDATED: . 15:36 EST, 25 October 2013 . The bishop of the Fargo Catholic Diocese in North Dakota has exposed potentially hundreds of church members in Fargo, Grand Forks and Jamestown to the hepatitis A virus in late September and early October. The state Health Department has issued an advisory of exposure for anyone who attended five churches and took communion. Bishop John Folda (pictured) of the Fargo Catholic Diocese in North Dakota has exposed potentially hundreds of church members in Fargo, Grand Forks and Jamestown to the hepatitis A . State Immunization Program Manager Molly Howell says the risk is low, but officials feel it's important to alert people to the possible exposure. The diocese announced on Monday that Bishop John Folda is taking time off after being diagnosed with hepatitis A. The diocese says he contracted the infection through contaminated food while attending a conference for newly ordained bishops in Italy last month. Symptoms of hepatitis A include fever, tiredness, loss of appetite, nausea and abdominal discomfort. Fargo Catholic Diocese in North Dakota (pictured) is where the bishop is located .",
       b'(CNN) -- Ralph Mata was an internal affairs lieutenant for the Miami-Dade Police Department, working in the division that investigates allegations of wrongdoing by cops. Outside the office, authorities allege that the 45-year-old longtime officer worked with a drug trafficking organization to help plan a murder plot and get guns. A criminal complaint unsealed in U.S. District Court in New Jersey Tuesday accuses Mata, also known as "The Milk Man," of using his role as a police officer to help the drug trafficking organization in exchange for money and gifts, including a Rolex watch. In one instance, the complaint alleges, Mata arranged to pay two assassins to kill rival drug dealers. The killers would pose as cops, pulling over their targets before shooting them, according to the complaint. "Ultimately, the (organization) decided not to move forward with the murder plot, but Mata still received a payment for setting up the meetings," federal prosecutors said in a statement. The complaint also alleges that Mata used his police badge to purchase weapons for drug traffickers. Mata, according to the complaint, then used contacts at the airport to transport the weapons in his carry-on luggage on trips from Miami to the Dominican Republic. Court documents released by investigators do not specify the name of the drug trafficking organization with which Mata allegedly conspired but says the organization has been importing narcotics from places such as Ecuador and the Dominican Republic by hiding them "inside shipping containers containing pallets of produce, including bananas." The organization "has been distributing narcotics in New Jersey and elsewhere," the complaint says. Authorities arrested Mata on Tuesday in Miami Gardens, Florida. It was not immediately clear whether Mata has an attorney, and police officials could not be immediately reached for comment. Mata has worked for the Miami-Dade Police Department since 1992, including directing investigations in Miami Gardens and working as a lieutenant in the K-9 unit at Miami International Airport, according to the complaint. Since March 2010, he had been working in the internal affairs division. Mata faces charges of aiding and abetting a conspiracy to distribute cocaine, conspiring to distribute cocaine and engaging in monetary transactions in property derived from specified unlawful activity. He is scheduled to appear in federal court in Florida on Wednesday. If convicted, Mata could face life in prison. CNN\'s Suzanne Presto contributed to this report.'],
      dtype=object)>

```



## Reference

https://www.tensorflow.org/datasets/overview

https://datascienceschool.net/view-notebook/cd2216fe352c4346bc1e5bb5efa9927e/

