#include <iostream>

using namespace std;

template<typename T>

struct Vector{
  T* d;
  int sz;
  int capa;

  Vector(){
    d = 0;
    clear();
  }
  void clear(){
    sz = 0;
    capa = 1;
    if(d) delete[] d;
    d = new T[capa];
  }
  void push_back(int val){
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

  T& operator[](int idx) {return d[idx];};
  T* begin() { return &d[0] ;};
  T* end() {return &d[sz];};

  int size() {return sz;};
};

template <typename T>
struct Queue{
  Vector<T> hdata;
  int top;

  Queue(){
    top = 0;
  }

  void push(T val){
    hdata.push_back(val);
  }

  void pop(){
    top++;
  }

  T& front() {return hdata[top];};

  bool empty(){return top >= hdata.sz;};
};

Vector<int> graph[1001];
bool visited_b[1001];
bool visited_d[1001];

Vector<int> dfs;
Vector<int> bfs;

void zwap(int* a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void merge(int s, int m, int e, int idx){
  int temp[e - s + 1];
  int i = s;
  int j = m + 1;
  int k = 0;

  while(i <= m && j <= e){
    if(graph[idx][i] <= graph[idx][j]) temp[k++] = graph[idx][i++];
    else temp[k++] = graph[idx][j++];
  }

  while(i <= m){
    temp[k++] = graph[idx][i++];
  }

  while(j <= e){
    temp[k++] = graph[idx][j++];
  }

  for(int h = 0; h < k; h++){
    graph[idx][s + h] = temp[h];
  }
}

void zort(int s, int e, int idx){
  if(s >= e) return;
  
  int mid = (s + e) / 2;
  zort(s, mid, idx);
  zort(mid + 1, e, idx);
  merge(s, mid, e, idx);
}

void travel(int cur);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, start;

  cin >> n >> m >> start;

  for(int i = 0; i < m; i++){
    int s, e;
    cin >> s >> e;
    graph[s].push_back(e);
    graph[e].push_back(s);
  }

  for(int i = 0; i <= n; i++){
    zort(0, graph[i].size() - 1, i);
  }

  travel(start);

  Queue<int> q;
  q.push(start);
  visited_b[start] = true;
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    bfs.push_back(cur);
    for(int i = 0; i < graph[cur].size(); i++){
      int next = graph[cur][i];
      if(visited_b[next]) continue;
      visited_b[next] = true;
      q.push(next);
      
    }
  }

  for(auto i : dfs){
    cout << i << " ";
  }
  cout << "\n";

  for(auto i : bfs){
    cout << i << " ";
  }
  return 0;
}

void travel(int cur){
  
  visited_d[cur] = true;
  dfs.push_back(cur);
  for(int i = 0; i < graph[cur].size(); i++){
    int next = graph[cur][i];
    if(visited_d[next]) continue;
    travel(next);
  }
}