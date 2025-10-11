#include <stdio.h>

int n, m;
int arr[8];
int used[9];
void backtracking(int step){
  if(step == m){
    for(int i = 0; i < m; i++){
      printf("%d ", arr[i]);
    }
    printf("\n");

    return;
  }

  for(int i = 1; i <= n; i++){
    if(used[i]) continue;

    used[i] = 1;
    arr[step] = i;
    backtracking(step+1);
    used[i] = 0;
  }
}

int main(){
  scanf("%d %d", &n, &m);

  backtracking(0);
  return 0;
}