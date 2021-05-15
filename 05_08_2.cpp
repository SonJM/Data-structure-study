#include <stdio.h>
#include <stdlib.h>

// C++ 에서는 사용자 정의 '집계 데이터 유형(user-defined aggregate data type)'을 생성할 수 있다.
// 집계 데이터 유형 : 여러 개별 변수를 함께 그룹화하는 데이터 유형 --> 구조체(struct)
// 구조체 : 하나 이상의 변수를 그룹 지어서 새로운 자료형을 정의하는 것 ( 멤버, 필드 )
// C++ 11에서는 초기값 설정 안하면 default값으로 초기화, 그 전까진 쓰레기 값이 대입
typedef struct stack {
    int data;
    struct stack* next;     // 자기 참조 구조체
    struct stack* prev;
}stack;

typedef struct tree {
    struct stack* head;
    struct stack* tail;
    int count;
}tree;

tree* init() {
    tree* newTree = (tree*)malloc(sizeof(tree));        // sizeof(tree) = 12(byte) / newTree 구조체 포인터에 메모리 할당

    newTree->head = NULL;
    newTree->tail = NULL;
    newTree->count = 0;
    return newTree;
}

void push_stack(int data, tree* newTree);
stack* memclear(tree* newTree);
void print(tree* newTree);

int main(int argc, char** argv) {
    tree* newTree = init();
    for (int i = 0; i < 10; i++) {
        push_stack(i, newTree);     // 10번 push_stack한다
    }
    print(newTree);

    printf("memory return\n");
    for (int i = 0; i < newTree->count; i++) {
        memclear(newTree);
    }
    free(newTree);

    return 0;
}

void push_stack(int data, tree* newTree) {
    stack* newStack = (stack*)malloc(sizeof(stack));
    stack* preStack = newTree->head;        // head = NULL

    newStack->data = data;

    if (newTree->count == 0) {
        newTree->head = newStack;
        newStack->next = newStack;
        newStack->prev = newStack;
    }
    else {
        for (int i = 1; i < newTree->count; i++) {
            preStack = preStack->next;      ////////////////////////////////////////////////////////////////////////////////////
        }
        preStack->next = newStack;
        preStack->next->prev = preStack;
    }
    newTree->tail = newStack;
    newTree->count++;
}

stack* memclear(tree* newTree) {
    stack* curStack;
    curStack = newTree->head;
    newTree->head = curStack->next;
    return curStack;
}

void print(tree* newTree) {
    stack* curStack;
    int i;
    printf("스택 자료구조는 LIFO (Last in First out)\n");
    for (i = 0, curStack = newTree->tail; i < newTree->count; i++, curStack = curStack->prev) {
        printf("%d ", curStack->data);
    }
    printf("\n");
}