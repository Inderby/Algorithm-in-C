#include <stdio.h>

int arr[1000];

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  for(int i = 1; i < n; i++){
    for(int j = 0; j < n - i; j++){
      if(arr[j] > arr[j + 1]){
        swap(&arr[j], &arr[j+1]);
      }
    }
  }

  for(int i = 0; i < n; i++){
    printf("%d\n", arr[i]);
  }
  return 0;
}