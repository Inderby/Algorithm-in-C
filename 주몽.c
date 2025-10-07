#include <stdio.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high){
  int pivot = arr[high];

  int i = low - 1;

  for(int j = low; j < high; j++){
    if(arr[j] < pivot){
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i+1], &arr[high]);

  return i+1;
}

void sort(int arr[], int low, int high){
  if(low < high){
    int pi = partition(arr, low, high);

    sort(arr, low, pi - 1);
    sort(arr, pi + 1, high);
  }
}

int main(){
  int n, m;

  int arr[15000] = {0};
  scanf("%d", &n);
  scanf("%d", &m);

  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  sort(arr, 0, n-1);

  int l = 0;
  int r = n - 1;
  int count = 0;


  while(l < r){
    int sum = arr[l] + arr[r];

    if(sum > m){
      r--;
    }else if(sum < m){
      l++;
    }else{
      count++;
      l++;
      r--;
    }
  }

  printf("%d", count);
}