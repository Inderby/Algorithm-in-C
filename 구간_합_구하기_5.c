#include <stdio.h>

int arr[1025][1025] = {0,};
int psum[1025][1025] = {0,};

int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      scanf("%d", &arr[i][j]);
      psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + arr[i][j];
    }
  }

  for(int i = 0; i < m; i++){
    int sx, sy, ex, ey;
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    printf("%d\n", psum[ex][ey] - psum[sx-1][ey] - psum[ex][sy-1] + psum[sx-1][sy-1]);
  }
  return 0;
}