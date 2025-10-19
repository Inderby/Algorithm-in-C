#include <iostream>

using namespace std;

int arr[100000];
int n;

int bi_search(int target){
  int left = 0;
  int right = n - 1;

  while(left <= right){
    int mid = left + (right - left) / 2;

    if(arr[mid] == target){
      return mid;
    }else if(arr[mid] < target){
      left = mid + 1;
    }else{
      right = mid - 1;
    }
  }
  return -1;
}

void merge(int left, int right, int mid){
  int temp[right - left + 1];

  int i = left;
  int j = mid+1;
  int k = 0;
  while(i <= mid && j <= right){
    if(arr[i] <= arr[j]) temp[k++] = arr[i++];
    else temp[k++] = arr[j++];
  }

  while(i <= mid) temp[k++] = arr[i++];
  while(j <= right) temp[k++] = arr[j++];

  for(i = 0; i < k; i++){
    arr[left + i] = temp[i];
  }
}

void merge_sort(int left, int right){
  if(left >= right) return;
  int mid = left + (right - left) / 2;

  merge_sort(left, mid);
  merge_sort(mid + 1, right);

  merge(left, right, mid);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  int m;
  cin >> m;

  merge_sort(0, n - 1);
  for(int i = 0; i < m; i++){
    int target;
    cin >> target;

    int idx = bi_search(target);

    if(idx == -1) cout << 0 << "\n";
    else cout << 1 << "\n";
  }
  return 0;
}