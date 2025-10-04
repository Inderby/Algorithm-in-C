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


void quick_sort_student(Student *arr, int left, int right, 
    int (*compare)(const Student*, const Student*)) {
    if (left >= right) return;
    
    Student pivot = arr[left];
    int i = left + 1;
    int j = right;
    
    while (i <= j) {
        while (i <= right && compare(&arr[i], &pivot) <= 0) i++;
        while (j > left && compare(&arr[j], &pivot) > 0) j--;
        if (i < j) {
            Student temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    arr[left] = arr[j];
    arr[j] = pivot;
    
    quick_sort_student(arr, left, j - 1, compare);
    quick_sort_student(arr, j + 1, right, compare);
}

// 사용 예시
int main() {
    Student students[] = {
        {"Alice", 20, 85.5},
        {"Bob", 19, 92.0},
        {"Charlie", 21, 78.3}
    };
    int size = 3;
    
    // 나이순 정렬
    quick_sort_student(students, 0, size - 1, compare_by_age);
    
    // 성적순 정렬
    quick_sort_student(students, 0, size - 1, compare_by_grade);
    
    return 0;
}