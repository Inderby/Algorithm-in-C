#include <stdio.h>

void swap(char *a, char *b){
  char temp = *a;
  *a = *b;
  *b = temp;
}

int main(){
  char arr[11] = {0};
  scanf("%s", arr);
  
  int length = 0;
  while(arr[length] != '\0'){
    length++;
  }
  
  for(int i = length - 1; i > 0; i--){
    char min = '9';
    min++;
    int min_idx = -1;
    for(int j = 0; j <= i; j++){
      if(min > arr[j]){
        min = arr[j];
        min_idx = j;
      }
    }

    swap(&arr[min_idx], &arr[i]);
  }

  for(int i = 0; i < length; i++){
    printf("%c", arr[i]);
  }
  return 0;
}