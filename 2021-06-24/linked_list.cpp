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

node* put_back(tree* Tree, int data) {   // �߰� ����
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

    printf("������ ����� ����: ");
    scanf("%d", &node_size);
    for (int i = 0; i < node_size; i++) {
        printf("%d��° ��� ������ �Է�: ", i + 1);
        scanf("%d", &node_data);
        insert(Tree, node_data);
    }
    printf("\n");
    printf("��� ���� �Ϸ�\n");
    while (true) {
        printf("-----------��� ����----------\n");
        printf("1. ����\n2. ����(tail)\n3. �˻�\n4. �߰�����\n5. �߰�����\n6. ���\n7. �������� ����\n8. �������� ����\n9. ��ü����\n");
        printf("-----------------------------\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
        {
            printf("����(insert)�� ������ ��: ");
            scanf("%d", &node_data);
            insert(Tree, node_data);
            break;
        }
        case 2:
        {
            free(put_back(Tree));
            printf("���� �Ϸ�\n");
            break;
        }
        case 3:
        {
            printf("�˻�(search)�� ������ ��: ");
            scanf("%d", &node_data);
            search(Tree, node_data);
            break;
        }
        case 4:
        {
            printf("-----------�߰� ����----------\n");
            printf("������ ������: ");
            scanf("%d", &node_data);
            printf("������ ��ġ: ");
            scanf("%d", &index);
            mid_insert(Tree, node_data, index);
            break;
        }
        case 5:
        {
            printf("-----------�߰� ����----------\n");
            printf("������ ������: ");
            scanf("%d", &node_data);
            free(put_back(Tree, node_data));
            break;
        }
        case 6:
        {
            printf("-----------��� ���----------\n");
            print(Tree);
            break;
        }
        case 7:
        {
            ascending_order(Tree);
            printf("�������� ���� �Ϸ�\n");
            break;
        }
        case 8:
        {
            descending_order(Tree);
            printf("�������� ���� �Ϸ�\n");
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