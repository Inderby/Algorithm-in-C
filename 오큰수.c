#include <stdio.h>

int stack[1000000];
int arr[1000000];
int ans[1000000];
int main(){
  int n;
  scanf("%d", &n);
  int top = -1;
  int idx = 0;
  for(int i = 0; i < n; i++){
    int num;
    scanf("%d", &num);
    arr[i] = num;

    if(top == -1 || arr[stack[top]] >= num){
      stack[++top] = i;
    }else {
      while(top >= 0 && arr[stack[top]] < num){
        ans[stack[top--]] = num;
      }
      stack[++top] = i;
    }
  }

  for(; top > -1; top--){
    ans[stack[top]] = -1;
  }

  for (int i = 0; i < n; i++)
  {
    printf("%d ", ans[i]);
  }
  
  return 0;
}