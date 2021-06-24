#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct tree {
    int count;
    struct node* head;
    struct node* tail;
}tree;

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
}node;

bool compare(int a, int b) {
    return a > b;
}

tree* init() {
    tree* newTree = (tree*)malloc(sizeof(tree));

    newTree->head = NULL;
    newTree->tail = NULL;
    newTree->count = 0;

    return newTree;
}

void insert(tree* Tree, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    node* preNode = Tree->head;

    newNode->data = data;
    if (Tree->count == 0) {
        Tree->head = newNode;
        Tree->tail = newNode;
    }
    else {
        for (int i = 1; i < Tree->count; i++) {
            preNode = preNode->next;
        }
        preNode->next = newNode;
        newNode->prev = preNode;
    }
    Tree->count++;
    Tree->tail = newNode;
}

void print(tree* Tree) {
    node* curNode;
    int i;
    for (i = 0, curNode = Tree->head; i < Tree->count; i++, curNode = curNode->next) {
        printf("%d ", curNode->data);
    }
    printf("\n");
}

void search(tree* Tree, int data) {
    node* curNode = Tree->head;
    int index = 1;
    while (true) {
        if (curNode->data == data) break;
        curNode = curNode->next;
        index++;
    }
    printf("index: %d , data: %d\n", index, curNode->data);
}

node* put_back(tree* Tree) {
    node* curNode = Tree->tail;
    curNode->prev = Tree->tail;
    Tree->count--;
    return curNode;
}

node* put_back(tree* Tree, int data) {   // 중간 삭제
    node* curNode = Tree->head;
    node* preNode;
    while (true) {
        if (curNode->data == data) break;
        curNode = curNode->next;
    }
    preNode = curNode->prev;
    preNode->next = curNode->next;
    preNode->next->prev = preNode;
    Tree->count--;
    return curNode;
}

void mid_insert(tree* Tree, int data, int index) {
    node* newNode = (node*)malloc(sizeof(node));
    node* curNode = Tree->head;

    newNode->data = data;
    Tree->count++;
    for (int i = 1; i < index; i++) {
        curNode = curNode->next;
    }
    if (index == 0) {
        newNode->next = curNode;
        curNode->prev = newNode;
        Tree->head = newNode;
    }
    else if (curNode == Tree->tail) {
        curNode->next = newNode;
        newNode->prev = curNode;
        Tree->tail = newNode;
    }
    else {
        newNode->next = curNode->next;
        curNode->next = newNode;
        newNode->next->prev = newNode;
        newNode->prev = curNode;
    }
    
}

void ascending_order(tree* Tree) {
    node* curNode;
    vector<int> arr;
    int i;
    
    for (i = 0, curNode = Tree->head; i < Tree->count; i++, curNode = curNode->next) {
        arr.push_back(curNode->data);
    }
    sort(arr.begin(), arr.end());
    for (i = 0, curNode = Tree->head; i < Tree->count; i++, curNode = curNode->next) {
        curNode->data = arr[i];
    }
}

void descending_order(tree* Tree) {
    node* curNode;
    vector<int> arr;
    int i;

    for (i = 0, curNode = Tree->head; i < Tree->count; i++, curNode = curNode->next) {
        arr.push_back(curNode->data);
    }
    sort(arr.begin(), arr.end(), compare);
    for (i = 0, curNode = Tree->head; i < Tree->count; i++, curNode = curNode->next) {
        curNode->data = arr[i];
    }
}

int main() {
    tree* Tree = init();
    int node_size, node_data, index, choice;

    printf("생성할 노드의 갯수: ");
    scanf("%d", &node_size);
    for (int i = 0; i < node_size; i++) {
        printf("%d번째 노드 데이터 입력: ", i + 1);
        scanf("%d", &node_data);
        insert(Tree, node_data);
    }
    printf("\n");
    printf("노드 생성 완료\n");
    while (true) {
        printf("-----------기능 선택----------\n");
        printf("1. 삽입\n2. 삭제(tail)\n3. 검색\n4. 중간삽입\n5. 중간삭제\n6. 출력\n7. 오름차순 정렬\n8. 내림차순 정렬\n9. 전체삭제\n");
        printf("-----------------------------\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
        {
            printf("삽입(insert)할 데이터 값: ");
            scanf("%d", &node_data);
            insert(Tree, node_data);
            break;
        }
        case 2:
        {
            free(put_back(Tree));
            printf("제거 완료\n");
            break;
        }
        case 3:
        {
            printf("검색(search)할 데이터 값: ");
            scanf("%d", &node_data);
            search(Tree, node_data);
            break;
        }
        case 4:
        {
            printf("-----------중간 삽입----------\n");
            printf("삽입할 데이터: ");
            scanf("%d", &node_data);
            printf("삽입할 위치: ");
            scanf("%d", &index);
            mid_insert(Tree, node_data, index);
            break;
        }
        case 5:
        {
            printf("-----------중간 삭제----------\n");
            printf("삭제할 데이터: ");
            scanf("%d", &node_data);
            free(put_back(Tree, node_data));
            break;
        }
        case 6:
        {
            printf("-----------노드 출력----------\n");
            print(Tree);
            break;
        }
        case 7:
        {
            ascending_order(Tree);
            printf("오름차순 정렬 완료\n");
            break;
        }
        case 8:
        {
            descending_order(Tree);
            printf("내림차순 정렬 완료\n");
            break;
        }
        case 9:
        {
            for (int i = 0; i < Tree->count; i++) {
                put_back(Tree);
            }
            free(Tree);
            return 0;
        }
        }
    }
}