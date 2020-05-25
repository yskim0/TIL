# Radix Sort (기수 정렬)

## 요약

- 자료 배열의 요소를 **자리수를 비교**해서 정렬한다.
- **sort by distribution**
- MSD -> LSD, LSD -> MSD 방향으로 가는 방식이 있다.
- 공간 효율성을 위해서는 LSD -> MSD 방향으로 가는 알고리즘이 더 유용함.

## 가정

- key들은 non-negative integer 이어야 함.
    - 또한 fixed base여야 함. (10진수라면 모든 key가 10진수.)

- 모든 key들은 같은 자릿수를 가진다.
    - 3, 81, 27과 같은 경우 자릿수를 맞추기 위해 3을 03으로 표기함.

## MSD -> LSD

- 가장 왼쪽 digit부터 차례대로 오른쪽 digit으로...
- 재귀적 구현
- bucket의 수가 매우 많이 필요함 -> 공간 낭비가 심한 알고리즘

## LSD -> MSD

- 가장 오른쪽 digit부터 차례대로 왼쪽 digit으로...
- bucket을 지우면서 하나의 리스트를 만듦.
    - 분배 -> 합침 -> 분배 -> 합침 ... 의 과정 순환
- 앞선 방법보다 공간 효율이 높음.

- **각각의 bucket을 연결리스트로 만들어서** 관리함.


## pseudocode

```cpp
void radixsort{
    for(i=1; i=numdigits; i++){
        distribute(i); // 분배
        coalesce; // 합침
    }
}

void distribute(index I){
    for(j=0; j<=9; j++)
        list[j] = NULL; // bucket 초기화. 10진수 가정
    p = masterlist; // 첫 번째 연결 노드 가리키는 pointer
    while (p!=NULL){
        j=value of ith digit in p->key;
        q = p;
        p = p->link;
        link q to the end of list[j]; // bucket j에 넣음
    }
}

void coalesce(){
    index j;
    masterlist = NULL;
    for(j=0; j<=9; j++)
        link the node in list[j] to the end of masterlist;
}
```


## (Example) C++ code 

구현은 추후에 하겠습니다.

### output

```
Enter the number of elements: 6
Enter elements:
9 45 23 71 80 55
Array before Sorting: 9 45 23 71 80 55
Array after Sorting: 9 23 45 55 71 80
```

## Analysis

- distribution : n :: key 개수
- coalesce : number of piles(=10) :: radix 수
- iteration : numdigits

- Total O(numdigits*(n+10))
    - consider numdigits a constant. ==> O(n)

- 이는 비교에 의한 정렬이 아니기 때문에 퀵 소트, 힙 소트와 굉장히 다름.

### Reference

이화여자대학교 이상호 교수님 컴퓨터 알고리즘 강의