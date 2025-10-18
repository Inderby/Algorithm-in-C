#include <stdio.h>

int n;

int grid[15];
int cnt;

int abs(int num){
  return num < 0 ? -1 * num : num;
}

int check(int row){
  for(int i = 0; i < row; i++){
    if(grid[i] == grid[row]) return 0;
    if(abs(i - row) == abs(grid[i] - grid[row])) return 0;
  }
  return 1;
}

void bactracking(int row){
  if(row == n){
    cnt++;
    return;
  }
  
  for(int i = 0; i < n; i++){
    grid[row] = i;
    if(check(row)){
      bactracking(row+1);
    }
  }
}

int main(){
  scanf("%d", &n);
  bactracking(0);
  printf("%d", cnt);
  return 0;
}