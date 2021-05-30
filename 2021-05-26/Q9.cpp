// 동적할당
// 1차원 배열 동적할당으로 구현하시오
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int num, i = 0;

	scanf("%d", &num);

	int* arr = (int*)malloc(sizeof(int) * num);
	while (i < num) {
		scanf("%d", arr + i);
		i++;
	}
	for (int i = 0; i < num; i++) {
		printf("%d ", *(arr + i));
	}

	free(arr);
}