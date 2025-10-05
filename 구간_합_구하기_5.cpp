#include <iostream>
#include <vector>

using namespace std;

int main(){
  cin.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;

  cin >> n >> m;

  vector<long> arr(n + 1, 0);
  vector<long> psum(n + 1, 0);
  vector<long> count(m + 1, 0);
  long ans = 0;
  
  
  for(int i = 1; i <= n; i++){
    cin >> arr[i];
    psum[i] = psum[i - 1] + arr[i];
  }

  for(int i = 1; i <= n; i++){
    psum[i] %= m;
    count[psum[i]]++;
  }

  ans += count[0];
  for(int i = 0; i < m; i++){
    if(count[i] > 1) {
      ans += (count[i] * (count[i] - 1)) / 2;
    }
  }

  cout << ans << "\n";
  return 0;
}