#include <iostream>

using namespace std;

int grid[10][10];
int papers[6] = {0 ,5, 5, 5, 5, 5};
int ans = 1000;

void backtracking(int xy, int cnt);
void fill(int x, int y, int size, int num);
bool check(int x, int y, int size);

int main(){
  cout.sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);


  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      cin >> grid[i][j];
    }
  }

  backtracking(0, 0);

  cout << (ans > 25 ? -1 : ans);
  return 0;
}

void backtracking(int xy, int cnt){
  if(xy == 100){
    ans = min(ans, cnt);
    return;
  }

  int x = xy % 10;
  int y = xy / 10;
  if(grid[x][y]){
    for(int i = 5; i > 0; i--){
      if(papers[i] > 0 && check(x, y, i)){
        fill(x, y, i, 0);
        papers[i]--;
        backtracking(xy + 1, cnt + 1);
        papers[i]++;
        fill(x, y, i, 1);
      }
    }
  }else{
    backtracking(xy + 1, cnt);
  }
}

void fill(int x, int y, int size, int num)
{
  for(int i = x; i < x + size; i++){
    for(int j = y; j < y + size; j++){
      grid[i][j] = num;
    }
  }
}

bool check(int x, int y, int size){
  if(x + size > 10 || y + size > 10) return false;

  for(int i = x; i < x + size; i++){
    for(int j = y; j < y + size; j++){
      if(grid[i][j] == 0) return false;
    }
  }
  return true;
}