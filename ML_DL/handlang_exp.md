## 이번 주(0415~0418) 실험 기록

[요약]
실험 1 Acc 139에폭 0.47
실험 2 acc (약 150에폭) 0.56
실험 3 acc 0.88
실험 4 진행중

### 1. YOLO hand tracking pre-trained weight[04/15]

이 경우에는 지영언니가 핸드 트레킹 모델을 사용했을 때 썼던 사람의 웨이트를 들고옴.
(https://github.com/yskim0/Handlang/commit/538759165905a170654f36d752da3717c8ece8c4#comments)


YOLOv2-tiny 모델을 다시 처음부터 학습시켰음.
실험 차원이었기 때문에 139에폭 돌리고 멈춤.
ACC = 0.47 정도...

- 유난히 못 맞추는 알파벳들이 있음. (a,t였나? 이외에도 비슷한 수화가 상당히 많음.)


- 이전과의 변동사항
    - 숫자 라벨 삭제(그로인해 cfg파일의 filters, num_classes 바뀜)


<br>


### 2. YOLOv2-tiny weight pre-trained weight[04/16]

YOLOv2 사이트에서 제공하는 weight를 가져옴.
1번과 마찬가지로 새로운 모델을 만들어서 시험함.

130에폭 되기도 전에 쯤에 테스트 해보았고, 결과는 acc 0.52정도 였음.
130에폭 쯤에는 이보다 더 나은 결과를 도출하였고, 마지막 테스트는 150에폭쯤에 했는데 acc 0.56정도 나옴.

- 1번과 마찬가지로 유난히 못 맞추는 알파벳이 있음. 
- 1,2의 공통 사항은 a를 너무 못맞추던데... 성공이 0이었음. 대신 a와 비슷한 t를 많이 예측했었음.


- weight 파일
    - yolov2 사이트에 있음.


- 이전과의 변동사항
    - 숫자 라벨 삭제(그로인해 cfg파일의 filters, num_classes 바뀜)

- 1번보다 성능이 아주 조금은 더 좋은 듯하여 웹에 올려 본 결과 만족스럽지 않음...


<br>



### 3. Inception-v3 classifier[04/17]

- 욜로에서 한번 벗어나보려고 시도해봄.

- 참고 사이트
    - http://solarisailab.com/archives/1422
    - https://maduinos.blogspot.com/2019/10/ml-tensorflow-03-inception-v3.html
    - 등등 ...

- 서버에서 너무 안되길래 로컬에서 먼저 시도해서 대략 성공한 듯 보였음.
다시 똑같은 방법으로 서버에서 시작해봄.

```
<env>
conda -> tensorflow 1.14.0설치하고 
tensorflow hub 설치

<local>
[로컬]
python retrain.py --bottleneck_dir=bottleneck --how_many_training_steps=500 --model_dir=model --output_graph=graph/retrained_graph.pb --output_labels=code/retrained_labels.txt --image_dir /Users/yeonsookim/inception/inception_dataset/


<server>
image_dir에 절대 경로를 넣어야 함.

python retrain.py --bottleneck_dir=bottleneck --how_many_training_steps=1000 --model_dir=model --output_graph=graph/retrained_graph.pb --output_labels=code/retrained_labels.txt --image_dir /mnt/home2/handlang/YS_2/ic_dataset/
```

- **이 모델은 classifier이기 때문에 우리 서비스에서 사용하려면 핸드 트레킹 모델 안에서 불러와서 사용해야 할 듯 함.**

- 역시 대기업답게 자동적으로 validation도 해주고 test도 해줘서 편했음.
    - bottleneck만 만들어지면 스텝 진행도 굉장히 빠름.
    - **final test accuracy = 88.7%**
        - 과연 리얼타임에서는 !?

- *문제는 우리가 지금까지 구축한 웹에 올리는 방법을 아직 모른다는 것...*



<br>


### 4. (진행 중)Tensorflow Object Detection Api
    - 3번은 classifier였기 때문에 사실상 우리가 원하는 게 아님. 따라서 Object detection으로...
    - tensorflow에서 이를 제공해주는 api가 있음.  
        - fast-rcnn, mobilnet, ssd 다 제공!
    - 우리 서비스가 어디서 구동될지 환경을 생각해보면,
        - 모바일이 아닌 데스크탑 PC임.
        - 빠르지만 상대적으로 덜 정확한 mobilnet 보다는 연산이 많더라도 정확성이 더 우수한 **fast-rcnn**을 선택했음.


- ~~가장 힘든 실험 ... 온갖 오류 다 봐서 매우 힘들었다.~~
구글링 해보면 거의 다 튜토리얼이고 own dataset으로 한 게 별로 없었다...

- 참고 사이트
    - https://github.com/tensorflow/models
    - https://you359.github.io/tensorflow%20models/Tensorflow-Object-Detection-API-Training/
    - https://yongyong-e.tistory.com/31?category=836820
    - http://solarisailab.com/archives/2422
    - https://m.blog.naver.com/PostView.nhn?blogId=bdh0727&logNo=221537759295&proxyReferer=https:%2F%2Fwww.google.com%2F
    - https://github.com/EdjeElectronics/TensorFlow-Object-Detection-API-Tutorial-Train-Multiple-Objects-Windows-10
    **(난 윈도우가 아니지만 제일 도움 됐었음)**
    https://github.com/EdjeElectronics/TensorFlow-Object-Detection-API-Tutorial-Train-Multiple-Objects-Windows-10/blob/master/translate/README.md
    (번역판도 제공)


- 정말 별별 에러 다 나와서 텐서플로우 버전을 몇번이나 바꿨는지 모르겠다~! 지금은(4/18/04:28) **로컬에서 학습 진행중이다**...
    - permission denied를 포함해서 그냥 진짜 별별 에러 다 나와서 로컬에서 해보고 안되면 접어야겠다 했는데 지금 되고 있다!!!!!!!!
    - ~~근데 팬 돌아가는 소리가 너무 커서 잠을 못 자겠다~~
