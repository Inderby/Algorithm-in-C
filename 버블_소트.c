#include <stdio.h>

// quick sort는 stable sort가 아니기 때문에 오답처리
typedef struct {
  int index;
  int data;
} Pair;

Pair arr[500001];

void swap(Pair *a, Pair *b){
  Pair temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int low, int high){
  int pivot = arr[high].data;
  int i = low - 1;
  for(int j = low; j < high; j++){
    if(arr[j].data < pivot){
      i++;
      swap(&arr[j], &arr[i]);
    }
  }

  swap(&arr[high], &arr[i + 1]);

  return i + 1;
}

void quick_sort(int low, int high){
  if(low >= high) return;

  int pi = partition(low, high);

  quick_sort(low, pi - 1);
  quick_sort(pi+1, high);
}

int main(){
  int n, max = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i].data);
    arr[i].index = i;
  }

  quick_sort(0, n - 1);

  for(int i = 0; i < n; i++){
    int gap = arr[i].index - i;

    if(max < gap){
      max = gap;
    }
  }

  printf("%d", max + 1);
  return 0;
}