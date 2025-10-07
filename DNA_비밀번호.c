#include <stdio.h>

char arr[1000000];

int main(){
  int s, p, a, c, g, t;
  int count[4] = {0};
  scanf("%d %d\n", &s, &p);

  scanf("%s", arr);

  scanf("%d %d %d %d", &a, &c, &g, &t);

  int result = 0;
  int l = 0;
  int r = 0;
  while(r < s){
    if(r - l < p){
      switch (arr[r])
      {
      case 'A' : count[0]++;
        break;
      case 'C' : count[1]++;
        break;
      case 'G' : count[2]++;
        break;
      case 'T' : count[3]++;
        break;
      default:
        break;
      }
      r++;
      if(count[0] >= a && count[1] >= c && count[2] >= g && count[3] >= t && r-l == p){
        result++;
      }
    }else{
      switch (arr[l])
      {
      case 'A' : count[0]--;
        break;
      case 'C' : count[1]--;
        break;
      case 'G' : count[2]--;
        break;
      case 'T' : count[3]--;
        break;
      default:
        break;
      }
      l++;
    }

    
  }
  printf("%d", result);
  return 0;
}