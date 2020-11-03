# anaconda 환경에서 pip install requirements 하는 법

그냥 pip install requirements 할 경우 버전 충돌 가능성 있음.
이럴 때는 해당 가상환경 경로의 /bin/pip install requirements.txt 를 사용

예시 `/mnt/home2/handlang/anaconda3/envs/dacon/bin/pip install -r requirements/build.txt`


