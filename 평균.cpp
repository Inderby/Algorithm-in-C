#include <iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  int arr[n];
  int max = 0;
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    
    sum += arr[i];

    if(max < arr[i]){
      max = arr[i];
    }
  }
  
  cout << (double)sum * 100.0 / max / n << "\n";

}