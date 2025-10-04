#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_SIZE 10007  // 소수로 설정하면 해시 충돌 감소
#define MAX_VAL 1000000   // 값의 최대 범위

// 체이닝 방식의 해시 테이블 노드
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Set 구조체
typedef struct {
    Node* table[HASH_SIZE];
    int size;
} Set;

// 해시 함수
int hash(int val) {
    return ((val % HASH_SIZE) + HASH_SIZE) % HASH_SIZE;  // 음수 처리
}

// Set 초기화
void init(Set* s) {
    s->size = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        s->table[i] = NULL;
    }
}

// 원소 삽입 (중복 허용 안함)
bool insert(Set* s, int val) {
    int idx = hash(val);
    Node* cur = s->table[idx];
    
    // 이미 존재하는지 확인
    while (cur) {
        if (cur->val == val) return false;  // 이미 존재
        cur = cur->next;
    }
    
    // 새 노드 추가
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->val = val;
    new_node->next = s->table[idx];
    s->table[idx] = new_node;
    s->size++;
    return true;
}

// 원소 존재 여부 확인
bool contains(Set* s, int val) {
    int idx = hash(val);
    Node* cur = s->table[idx];
    
    while (cur) {
        if (cur->val == val) return true;
        cur = cur->next;
    }
    return false;
}

// 원소 삭제
bool remove_val(Set* s, int val) {
    int idx = hash(val);
    Node* cur = s->table[idx];
    Node* prev = NULL;
    
    while (cur) {
        if (cur->val == val) {
            if (prev) prev->next = cur->next;
            else s->table[idx] = cur->next;
            
            free(cur);
            s->size--;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

// Set 크기 반환
int get_size(Set* s) {
    return s->size;
}

// Set이 비어있는지 확인
bool is_empty(Set* s) {
    return s->size == 0;
}

// Set 전체 출력 (디버깅용)
void print_set(Set* s) {
    printf("Set size: %d\n", s->size);
    printf("Elements: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* cur = s->table[i];
        while (cur) {
            printf("%d ", cur->val);
            cur = cur->next;
        }
    }
    printf("\n");
}

// Set 메모리 해제
void clear(Set* s) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* cur = s->table[i];
        while (cur) {
            Node* temp = cur;
            cur = cur->next;
            free(temp);
        }
        s->table[i] = NULL;
    }
    s->size = 0;
}

// ===== 추가 유틸리티 함수들 =====

// 두 Set의 교집합 개수 구하기
int intersection_count(Set* s1, Set* s2) {
    int count = 0;
    Set* smaller = (s1->size < s2->size) ? s1 : s2;
    Set* larger = (s1->size < s2->size) ? s2 : s1;
    
    // 작은 set을 순회하며 큰 set에 있는지 확인
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* cur = smaller->table[i];
        while (cur) {
            if (contains(larger, cur->val)) count++;
            cur = cur->next;
        }
    }
    return count;
}

// 배열을 Set으로 변환 (중복 제거)
void array_to_set(Set* s, int arr[], int n) {
    init(s);
    for (int i = 0; i < n; i++) {
        insert(s, arr[i]);
    }
}