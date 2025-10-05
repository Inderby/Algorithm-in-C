#include <stdio.h>

int main(){
    int size = 0;
    scanf("%d\n", &size);
    char arr[100] = {0,};
    for(int i = 0; i < size; i++){
        scanf("%c", &arr[i]);
    }

    int ans = 0;

    for(int i = 0; i < size; i++){
        ans += arr[i] - '0';
    }

    printf("%d", ans);
    return 0;
}