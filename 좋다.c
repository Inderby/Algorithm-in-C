#include <stdio.h>

void swap(long *a, long *b){
  long temp = *a;
  *a = *b;
  *b = temp;
}

long partition(long arr[], long low, long high){
  long pivot = arr[high];
  long i = low - 1;

  for(long j = low; j < high; j++){
    if(arr[j] < pivot){
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i+1], &arr[high]);
  return i + 1;
}

void sort(long arr[], long low, long high){
  if(low < high){
    long pi = partition(arr, low, high);

    sort(arr, low, pi - 1);
    sort(arr, pi + 1, high);
  }
}

int main(){

  int n;
  scanf("%d", &n);

  long arr[2000];

  for(long i = 0; i < n; i++){
    scanf("%ld", &arr[i]);
  }

  sort(arr, 0, n - 1);

  int count = 0;
  for(long i = 0; i < n; i++){
    long target = arr[i];
    long l = 0;
    long r = n - 1;
    long possible = 0;
    while(l < r){
      long sum = arr[l] + arr[r];

      if(sum > target){
        r--;
      }else if(sum < target){
        l++;
      }else{
        if(r != i && l != i){
          possible++;
          break;
        }else if(r == i){
          r--;
        }else{
          l++;
        }
      }
    }

    if(possible){
      count++;
    }
  }

  printf("%d", count);
  return 0;
}