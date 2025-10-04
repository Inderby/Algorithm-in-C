#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_SIZE 10007  // 소수로 설정하면 해시 충돌 감소
#define MAX_VAL 1000000   // 값의 최대 범위

typedef struct {
    bool exist[MAX_VAL + 1];
    int size;
} SimpleSet;

void simple_init(SimpleSet* s) {
    for (int i = 0; i <= MAX_VAL; i++) s->exist[i] = false;
    s->size = 0;
}

bool simple_insert(SimpleSet* s, int val) {
    if (val < 0 || val > MAX_VAL) return false;
    if (!s->exist[val]) {
        s->exist[val] = true;
        s->size++;
        return true;
    }
    return false;
}

bool simple_contains(SimpleSet* s, int val) {
    if (val < 0 || val > MAX_VAL) return false;
    return s->exist[val];
}

bool simple_remove(SimpleSet* s, int val) {
    if (val < 0 || val > MAX_VAL) return false;
    if (s->exist[val]) {
        s->exist[val] = false;
        s->size--;
        return true;
    }
    return false;
}

// ===== 사용 예제 =====
int main() {
    SimpleSet s;
    init(&s);
    
    // 삽입 테스트
    insert(&s, 10);
    insert(&s, 20);
    insert(&s, 30);
    insert(&s, 10);  // 중복 삽입 시도
    
    printf("Size: %d\n", get_size(&s));  // 3
    printf("Contains 20: %s\n", contains(&s, 20) ? "Yes" : "No");  // Yes
    printf("Contains 40: %s\n", contains(&s, 40) ? "Yes" : "No");  // No
    
    // 삭제 테스트
    remove_val(&s, 20);
    printf("After removing 20, contains 20: %s\n", 
           contains(&s, 20) ? "Yes" : "No");  // No
    
    // 배열에서 중복 제거
    int arr[] = {1, 2, 3, 2, 1, 4, 5, 4};
    SimpleSet s2;
    array_to_set(&s2, arr, 8);
    printf("Unique elements count: %d\n", get_size(&s2));  // 5
    
    // 메모리 해제
    clear(&s);
    clear(&s2);
    
    // Simple Set 사용 예제 (값 범위가 작을 때)
    SimpleSet ss;
    simple_init(&ss);
    simple_insert(&ss, 100);
    simple_insert(&ss, 200);
    printf("Simple Set contains 100: %s\n", 
           simple_contains(&ss, 100) ? "Yes" : "No");  // Yes
    
    return 0;
}