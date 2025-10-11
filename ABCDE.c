#include <stdio.h>

int n, m;
int graph[2001][2001];
int degree[2001];
int flag;

void dfs(int cur, int depth, int visited[]){
  if(flag || visited[cur]) return;
  if(depth == 4){
    flag = 1;
    return;
  }

  
  for(int i = 0; i < degree[cur]; i++){
    if(visited[graph[cur][i]]) continue;
    visited[cur]++;
    dfs(graph[cur][i], depth+1, visited);
    visited[cur]--;
  }

  return;
}

int main(){
  
  scanf("%d %d", &n, &m);

  for(int i = 0; i < m; i++){
    int s, e;
    scanf("%d  %d", &s, &e);
    
    graph[s][degree[s]++] = e;
    graph[e][degree[e]++] = s;
  }

  for(int i = 0; i < n; i++){
    int visited[2001] = {0};
    dfs(i, 0, visited);
  }

  printf("%d", flag);
  return 0;
}