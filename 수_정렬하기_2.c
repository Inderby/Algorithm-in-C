#include <stdio.h>

int arr[1000000];

void merge(int left, int mid, int right){
  int temp[right - left + 1];
  
  int i = left;
  int j = mid + 1;
  int k = 0;

  while(i <= mid && j <= right){
    if(arr[i] <= arr[j]) temp[k++] = arr[i++];
    else temp[k++] = arr[j++];
  }

  while(i <= mid) temp[k++] = arr[i++];
  while(j <= right) temp[k++] = arr[j++];

  for(i = 0; i < k; i++){
    arr[left + i] = temp[i];
  }
}

void mergesort(int left, int right){
  if(left >= right) return;

  int mid = (left + right) / 2;
  mergesort(left, mid);
  mergesort(mid + 1, right);
  merge(left, mid, right);
}

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  mergesort(0, n - 1);

  for(int i = 0; i < n; i++){
    printf("%d\n", arr[i]);
  }
  return 0;
}