#include <stdio.h>

int abs(int a){
    return a > 0 ? a : -a;
}

int main() {
    int A, B, x, y;
    scanf("%d %d %d %d", &A, &B, &x, &y);
    // Please write your code here.
    int ans = 9999;
    int a2x = abs(A - x);
    int a2y = abs(A - y);
    int y2b = abs(B - y);
    int x2b = abs(B - x);
    int a2b = abs(A - B);

    int a2x2b = a2x + y2b;
    int a2y2b = a2y + x2b;
    
    ans = a2x2b < ans ? a2x2b : ans;
    ans = a2y2b < ans ? a2y2b : ans;
    ans = a2b < ans ? a2b : ans;

    printf("%d", ans);
    return 0;
}