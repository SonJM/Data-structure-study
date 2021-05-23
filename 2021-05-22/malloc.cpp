#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int schoolnum;
	char name[20];
	char address[50];
}node;

int main() {
	node* n = (node*)malloc(sizeof(node));
	char buf[20] = "lsh";
	char buf2[50] = "suwon jangangu";
	n->schoolnum = 2021710565;
	strcpy(n->name, buf);
	strcpy(n->address, buf2);

	printf("%d\n%s\n%s\n", n->schoolnum, n->name, n->address);

	free(n);

	return 0;
}
