
IoU = 교집합 영역 넓이 / 합집합 영역 넓이
<br><br>

응용

- R-CNN : SVM을 학습 시킬 때 라벨링 과정에서 사용
  - ground truth와 proposed region 사이의 IoU 값을 계산해 0.5 이상인 경우 해당 region을 객체로 바라보고 ground truth와 같은 class로 라벨링
  
- NMS(Non-maximum suppresion) 에서도 사용됨
