#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  cin.sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<pair<int, int> > v(n);

  

  for(int i = 0; i < n; i++){
    cin >> v[i].first;
    v[i].second = i;
  }

  sort(v.begin(), v.end());

  int max = 0;

  for(int i = 0; i < n; i++){
    if(max < v[i].second - i){
      max = v[i].second - i;
    }
  }
  
  cout << max + 1;
  return 0;
}