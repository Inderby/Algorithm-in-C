#include <stdio.h>

int n;
int num_1[4] = {2, 3, 5, 7};
int num_n[5] = {1, 3, 5, 7, 9};

int check(int num){
  for(int i = 2; i < num / 2; i++){
    if(num % i == 0) return 0;
  }

  return 1;
}

void dfs(int num, int step){
  if(step > n){
    printf("%d\n", num / 10);
    return;
  }

  if(step == 1){
    for(int i = 0; i < 4; i++){
      if(!check(num + num_1[i])) continue;

      dfs((num + num_1[i]) * 10, step + 1);
    }
  }else{
    for(int i = 0; i < 5; i++){
      if(!check(num + num_n[i])) continue;
      dfs((num + num_n[i]) * 10, step + 1);
    }
  }
}

int main(){
  scanf("%d", &n);

  dfs(0, 1);
  return 0;
}