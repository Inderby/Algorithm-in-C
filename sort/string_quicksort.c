#include <stdio.h>

int string_compare(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (*str1 < *str2) return -1;
        if (*str1 > *str2) return 1;
        str1++;
        str2++;
    }
    if (*str1) return 1;
    if (*str2) return -1;
    return 0;
}

void quick_sort_string(char **arr, int left, int right){
    if(left >= right) return;
    
    char *pivot = arr[left];
    int i = left + 1;
    int j = right;
    
    while(i <= j){
        while(i <= right && string_compare(arr[i], pivot) <= 0) i++;
        while(j > left && string_compare(arr[j], pivot) > 0) j--;
        if(i < j){
            char *temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    arr[left] = arr[j];
    arr[j] = pivot;

    quick_sort_string(arr, left, j - 1);
    quick_sort_string(arr, j + 1, right);
}

int main(){
    char *names[] = {"zebra", "apple", "banana", "cat", "dog"};
    int size = 5;
    
    quick_sort_string(names, 0, size - 1);
    
    for(int i = 0; i < size; i++){
        printf("%s ", names[i]);
    }
    // 출력: apple banana cat dog zebra
    
    return 0;
}