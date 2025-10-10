#include <stdio.h>

typedef struct {
  int data[100001];
  int size;
} PriorityQueue;

PriorityQueue pq;

int abs(int a){
  return a < 0 ? a * -1 : a;
}

int compare(int a, int b){
  if(abs(a) < abs(b))
    return a;
  else if(abs(a) > abs(b)){
    return b;
  }else
    return a > b ? b : a;
}

void init(){
  pq.size = 0;
}

void push(int x){
  int i = ++pq.size;

  while(i > 1 && compare(x, pq.data[i/2]) == x){
    pq.data[i] = pq.data[i/2];
    i /= 2;
  }

  pq.data[i] = x;
}

int pop(){
  if(pq.size == 0) return 0;

  int ret = pq.data[1];
  int tmp = pq.data[pq.size--];
  int parent = 1, child = 2;

  while(child <= pq.size){
    if(child < pq.size && compare(pq.data[child], pq.data[child+1]) == pq.data[child+1])
      child++;
    if(compare(pq.data[child], tmp) == tmp) break;

    pq.data[parent] = pq.data[child];

    parent = child;
    child *= 2;
  }
  pq.data[parent] = tmp;

  return ret;
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    int command;
    scanf("%d", &command);

    if(command == 0){
      printf("%d\n", pop());
    }else{
      push(command);
    }
  }
}