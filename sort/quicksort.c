#include <stdio.h>

void quick_sort(int *arr, int left, int right){
    if(left >= right) return;
    int pivot = arr[left];
    int i = left+1;
    int j = right;
    
    while(i <= j){
        while(i <= right && arr[i] <= pivot) i++;
        while(j > left && arr[j] >= pivot) j--;
        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    arr[left] = arr[j];
    arr[j] = pivot;

    quick_sort(arr, left, j - 1);
    quick_sort(arr, j + 1, right);
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];

    quick_sort(arr, 0, n - 1);
    return 0;
}