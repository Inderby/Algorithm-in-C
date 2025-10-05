#include <iostream>
using namespace std;

int main(){
  cin.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, m;
  cin >> n >> m;


  int psum[n + 1];
  psum[0] = 0;
  for(int i = 1; i <= n; i++){
    int num;
    cin >> num;
    psum[i] = psum[i - 1] + num;
  }

  for(int i = 0; i < m; i++){
    int s, e;
    cin >> s >> e;

    cout << psum[e] - psum[s-1] << "\n";
  }
  return 0;
}