#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);
  int arr[1000] = {0};

  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  int idx = 1;
  while(idx != n){
    int num = arr[idx];
    int insert_idx = idx;
    for(int i = idx - 1; i >= 0; i--){
      if(arr[i] > num){
        insert_idx = i;
      }else{
        break;
      }
    }

    for(int i = idx - 1; i >= insert_idx; i--){
      arr[i + 1] = arr[i];
    }

    arr[insert_idx] = num;
    idx++;
  }

  int ans = 0;
  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += arr[i];
    ans += sum;
  }

  printf("%d", ans);
  return 0;
}