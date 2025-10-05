#include <stdio.h>

int main(){
  int n;
  int ans = 1;
  scanf("%d", &n);

  long target = n;
  long num = 0;

  n /= 2;
  n += 1;
  
  int l = 1;
  for(int r = 1; r <= n; r++){
    num += r;
    if(num > target){
      while(l < r && num > target){
        num -= l;
        l++;
      }
    }

    if(num == target && r != l){
      ans++;
    }
  }

  printf("%d", ans);
  return 0;
}