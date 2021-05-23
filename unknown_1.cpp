#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 256

typedef struct node {
    struct node* left;
    struct node* right;
    int data;
}node;

typedef struct tree {
    struct tree* next;
    int data;
}tree;

tree* root = NULL;
int size = 1;
node binary[MAX_SIZE];

tree* insert(tree* root, int data) {
    if (root == NULL) {
        root = (tree*)malloc(sizeof(tree));
        root->next = NULL;
        root->data = data;
        size++;
        return root;
    }
    else {
        root->next = insert(root->next, data);
        return root;
    }
}

void print(node* root) {
    if (root) {
        printf("%d ", root->data);
        print(root->left);
        print(root->right);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int k) {
    int i = k;
    if (k == 1) {
        return;
    }
    do {
        if (i != 1 && binary[i].data > binary[i / 2].data) swap(&binary[i].data, &binary[i / 2].data);
        i = i / 2;
    } while (i != 1);
    if (binary[k / 2].data < binary[k].data) swap(&binary[k / 2].data, &binary[k].data);

    heapify(k - 1);
}

int main() {
    int size = 15;
    for (int i = 1; i <= size; i++) {
        int key = i - 1;
        root = insert(root, key);
        binary[i].data = root->data;
        binary[i].left = NULL;
        binary[i].right = NULL;

        root = root->next;

        if (i % 2 == 0) {
            binary[i / 2].left = &binary[i];
        }
        else {
            binary[i / 2].right = &binary[i];
        }
    }

    heapify(size);
    //   print(&binary[1]);
    for (int i = 1; i <= size; i++) {
        printf("%d ", binary[i].data);
    }
    printf("\n");

    return 0;
}