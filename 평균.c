#include <stdio.h>

int main(){

  int n;
  scanf("%d\n", &n);

  int max = 0, sum = 0;

  for(int i = 0; i < n; i++){
    int num = 0;
    scanf("%d ", &num);
    sum += num;
    if(max < num){
      max = num;
    }
  }

  printf("%f", sum * 100.0 / max / n);
  return 0;
}