#include <iostream>

using namespace std;

template <typename T>
struct Vector{
  T* d;
  int sz;
  int capa;

  Vector(){
    sz = 0;
    capa = 1;
    d = new T[capa];
  }

  void push_back(T val){
    if(sz == capa){
      capa *= 2;
      
      T* nd = new T[capa];

      for(int i = 0; i < sz; i++){
        nd[i] = d[i];
      }

      delete[] d;
      d = nd;
    }

    d[sz++] = val;
  }

  void clear(){
    delete[] d;
    sz = 0;
    capa = 1;
  }

  int size() {return sz;};

  T& operator[](int idx) {return d[idx];};
};

Vector<pair<int, int> > graph[100001];

int visited[100001] = {-1};

void dfs(int cur, int dis);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int node;
    cin >> node;

    
    do{
      int input, distance;
      cin >> input;
      if(input == -1) break;

      cin >> distance;
      graph[node].push_back({input, distance});
    } while(1);
  }

  for(int i = 1; i <= n; i++){
    visited[i] = -1;
  }

  dfs(1, 0);

  int max_nod = 1;
  int max_dis = 1;
  for(int i = 1; i <= n; i++){

    if(max_dis < visited[i]){
      max_nod = i;
      max_dis = visited[i];
    }
    
    visited[i] = -1;
  }

  dfs(max_nod, 0);
  
  int ans = -1;
  for(int i = 1; i <= n; i++){
    if(ans < visited[i]){
      ans = visited[i];
    }
  }

  cout << ans;
  return 0;
}

void dfs(int cur, int dis){
  if(visited[cur] != -1) return;

  visited[cur] = dis;

  for(int i = 0; i < graph[cur].size(); i++){
    auto& node = graph[cur][i];

    if(visited[node.first] != -1) continue;
    dfs(node.first, dis + node.second);
  }
}