#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}node;

typedef struct tree {
	struct node* head;
	int count;
	struct node* tail;
}tree;

void create(int data, tree* newTree);
void memclear(tree* newTree);
void print(tree* newTree);

tree* init() {
	tree* newTree = (tree*)malloc(sizeof(tree));
	
	newTree->head = NULL;
	newTree->tail = NULL;
	newTree->count = 0;

	return newTree;
}

int main(int argc, char** argv) {
	tree* newTree = init();
	int count = newTree->count;
	for (int i = 0; i < 10; i++) {
		create(i, newTree);
	}
	print(newTree);

	printf("memory return\n");
	for (int i = 0; i < count; i++) {
		memclear(newTree);
	}
	free(newTree);

	return 0;
}

void create(int data, tree* newTree) {
	node* newNode = (node*)malloc(sizeof(node));
	node* nextNode = newTree->head;

	newNode->data = data;

	if (newTree->count == 0) {
		newTree->head = newNode;
		newNode->link = newNode;
	}
	else {
		for (int i = 1; i < newTree->count; i++) {	//
			nextNode = nextNode->link;			// newTree->head부터 새로 생긴 newNode까지 연결
		}
		nextNode->link = newNode;
	}
	newTree->tail = newNode;
	newTree->count++;
}

void memclear(tree* newTree) {
	node* curNode;
	curNode = newTree->head;
	newTree->head = curNode->link;
	free(curNode);
	newTree->count--;
}

void print(tree* newTree) {
	node* curNode = newTree->head;
	int i = 0;
	printf("단일 링크 리스트 출력 -> ");
	for (i = 0; i < newTree->count; i++) {
		printf("%d ", curNode->data);
		curNode = curNode->link;
	}
	printf("\n");
}