#include <stdio.h>
#include <stdlib.h>

int arr[5000000];

int compare(const void *a, const void *b){
  return *(int *)a - *(int*)b;
}

int main(){
  int n, k;
  scanf("%d %d", &n, &k);

  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  qsort(arr, n, sizeof(int), compare);

  printf("%d", arr[k - 1]);
}