#include <stdio.h>
#define MAX_SIZE 100001

// min heap
typedef struct{
  int heap[MAX_SIZE];
  int size;
} PriorityQueue;

PriorityQueue pq;

void init(){
  pq.size = 0;
}

void push(int x){
  int i = ++pq.size;
  while(i > 1 && x < pq.heap[i/2]){
    pq.heap[i] = pq.heap[i/2];
    i /= 2;
  }
  pq.heap[i] = x;
}

int pop(){
  if(pq.size == 0) return -1;

  int ret = pq.heap[1];
  int tmp = pq.heap[pq.size--];
  int parent = 1, child = 2;

  while(child <= pq.size){
    if(child < pq.size && pq.heap[child] > pq.heap[child + 1])
      child++;
    if(tmp <= pq.heap[child]) break;

    pq.heap[parent] = pq.heap[child];
    parent = child;
    child *= 2;
  }

  pq.heap[parent] = tmp;
  return ret;
}

int top(){
  return pq.size == 0 ? -1 : pq.heap[1];
}

int empty(){
  return pq.size == 0;
}