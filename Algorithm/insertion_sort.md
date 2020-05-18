# Insertion Sort (삽입 정렬)

## 요약

- 자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여, 자신의 위치를 찾아 삽입함으로써 정렬을 완성하는 알고리즘.

## 개념

- 두 번째 자료부터 시작하여 앞의 자료들과 비교하여 삽입할 위치를 지정한 후 자료를 옮기고, 지정한 자리에 자료를 삽입하여 정렬.

- 처음 Key 값은 두 번째 자료부터 시작한다.

## pseudocode

```
Begin
   for i := 1 to size-1 do
      key := array[i]
      j := i
      while j > 0 AND array[j-1] > key do
         array[j] := array[j-1];
         j := j – 1
      done
      array[j] := key
   done
End
```


## (Example) C++ code 

```cpp
#include<iostream>
using namespace std;
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void insertionSort(int *array, int size) {
   int key, j;
   for(int i = 1; i<size; i++) {
      key = array[i];//take value
      j = i;
      while(j > 0 && array[j-1]>key) {
         array[j] = array[j-1];
         j--;
      }
      array[j] = key;   //insert in right place
   }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];    //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   insertionSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
}
```

### output

```
Enter the number of elements: 6
Enter elements:
9 45 23 71 80 55
Array before Sorting: 9 45 23 71 80 55
Array after Sorting: 9 23 45 55 71 80
```

## complexity

worst case of time complexity : O(n^2) comparisons & swaps


### Reference

[Insertion sort in 2 minutes](https://www.youtube.com/watch?v=JU767SDMDvA)