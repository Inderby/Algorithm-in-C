#include <iostream>

#define MAX_SIZE 80000

using namespace std;

int dx[8] = {0, 1, -1, 0};
int dy[8] = {1, 0, 0, -1};



template <typename T>
struct Queue{
  T data[MAX_SIZE];
  int front;
  int rear;
  int cnt;
  Queue(){
    front = 0;
    rear = 0;
    cnt = 0;
  }

  bool empty(){
    return cnt == 0;
  }

  void enqueue(T val){
    data[rear++] = val;
    if(rear == MAX_SIZE){
      rear %= MAX_SIZE;
    }
    cnt++;
  }

  T dequeue(){
    T ret = data[front++];
    if(front == MAX_SIZE){
      front %= MAX_SIZE;
    }
    cnt--;
    return ret;
  }
};

struct Info{
  int x;
  int y;
  int step;
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;

  cin >> n >> m;

  string map[n];
  bool visited[n][m];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      visited[i][j] = false;
    }
  }
  for(int i = 0; i < n; i++){
    cin >> map[i];
  }

  Queue<Info> q;
  q.enqueue({0, 0, 1});
  visited[0][0] = true;

  while(!q.empty()){
    Info cur = q.dequeue();
    
    if(cur.x == n - 1 && cur.y == m - 1){
      cout << cur.step;
      break;
    }

    for(int i = 0; i < 4; i++){
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];
      if(visited[nx][ny]) continue;
      if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == '1'){
        q.enqueue({nx, ny, cur.step+1});
        visited[nx][ny] = true;
      }
    }
  }
  return 0;
}