#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}stack;

typedef struct tree {
	struct node* head;
	int count;
	struct node* tail;
}tree;

void create_stack(int data, tree* newTree);

tree* init() {
	tree* newTree = (tree*)malloc(sizeof(tree));
	
	newTree->head = NULL;
	newTree->tail = NULL;
	newTree->count = 0;

	return(newTree);
}

int main(int argc, char** argv) {
	tree* newTree = init();
	
	for (int i = 0; i < 10; i++) {
		create_stack(i, newTree);
	}

}

void create_stack(int data, tree* newTree) {
	node* newNode = (node*)malloc(sizeof(node));
	node* nextNode = newTree->head;

	newNode->data = data;

	if (newTree->count == 0) {
		newTree->head = newNode;
		newNode->link = newNode;	// 자기 참조..?
	}
	else {
		for (int i = 0; i < newTree->count; i++) {	//
			nextNode->link = newNode;				// newTree->head부터 새로 생긴 newNode까지 연결
		}			
	}
	newTree->tail = newNode;
	newTree->count++;
}

stack* memclear(tree* newTree) {

}