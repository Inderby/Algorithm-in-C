#include <stdio.h>

int main(){
  int n;

  scanf("%d", &n);
  int stack[100001] = {0};
  int arr[100001] = {0};
  char ans[200001];
  int s_top = 0;
  int a_top = 1;
  int idx = 1;
  for(int i = 1; i <= n; i++){
    scanf("%d", &arr[i]);
  }

  for (int i = 1; i <= n; i++)
  {
    ans[idx++] = '+';
    stack[++s_top] = i;
    while(s_top >= 1 && stack[s_top] == arr[a_top]){
      a_top++;
      s_top--;
      ans[idx++] = '-';
    }
  }
  
  if(s_top == 0){
    for(int i = 1; i < idx; i++){
      printf("%c\n", ans[i]);
    }
  }else{
    printf("NO");
  }
  return 0;
}