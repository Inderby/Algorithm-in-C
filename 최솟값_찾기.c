#include <stdio.h>

typedef struct node{
  int index;
  long number;
} Node;

long arr[5000000];
Node deck[5000000];
int front = 0, back = 0;


int main(){
  int n, l;

  scanf("%d %d", &n, &l);

  for(int i = 0; i < n; i++){
    scanf("%ld", &arr[i]);
  }

  for(int i = 0; i < n; i++){
    while(back > front && deck[back-1].number > arr[i]){
        back--;
    }
    
    deck[back].index = i;
    deck[back].number = arr[i];
    back++;
    
    // 윈도우 크기 체크 최적화
    if(i - deck[front].index >= l){
        front++;
    }
    
    printf("%ld ", deck[front].number);
  }
  return 0;
}