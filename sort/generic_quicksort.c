#include <stdio.h>

// 학생 구조체 예시
typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

// 비교 함수들 (반환값: 음수=앞이 작음, 0=같음, 양수=앞이 큼)
int compare_by_age(const void *a, const void *b) {
    Student *s1 = (Student*)a;
    Student *s2 = (Student*)b;
    return s1->age - s2->age;
}

int compare_by_grade(const void *a, const void *b) {
    Student *s1 = (Student*)a;
    Student *s2 = (Student*)b;
    if (s1->grade < s2->grade) return -1;
    if (s1->grade > s2->grade) return 1;
    return 0;
}

// 일반화된 Quick Sort
void quick_sort_generic(void *arr, int left, int right, size_t elem_size, 
    int (*compare)(const void*, const void*)) {
    
        if (left >= right) return;
        
        char *base = (char*)arr;
        char *pivot = malloc(elem_size);
        memcpy(pivot, base + left * elem_size, elem_size);
        
        int i = left + 1;
        int j = right;
        
        while (i <= j) {
            while (i <= right && compare(base + i * elem_size, pivot) <= 0) i++;
            while (j > left && compare(base + j * elem_size, pivot) > 0) j--;
            if (i < j) {
                // 요소 교환
                char *temp = malloc(elem_size);
                memcpy(temp, base + i * elem_size, elem_size);
                memcpy(base + i * elem_size, base + j * elem_size, elem_size);
                memcpy(base + j * elem_size, temp, elem_size);
                free(temp);
            }
        }
        
        // pivot과 j 위치 교환
        memcpy(base + left * elem_size, base + j * elem_size, elem_size);
        memcpy(base + j * elem_size, pivot, elem_size);
        free(pivot);
        
        quick_sort_generic(arr, left, j - 1, elem_size, compare);
        quick_sort_generic(arr, j + 1, right, elem_size, compare);
}