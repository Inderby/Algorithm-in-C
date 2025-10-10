#include <stdio.h>

int arr[10000000];

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(){
  int n;
  int front = 1;
  int back = 0;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    arr[i] = i;
    back++;
  }

  while(back - front != 0){
    front++;
    arr[++back] = arr[front++];
  }

  printf("%d", arr[front]);
  return 0;
}