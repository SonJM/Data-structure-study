// 동적할당
// 2차원 배열 동적할당으로 구현하고, 홀수n 을 출력하시오. (0<=n<=100)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int num, n = -1;
	scanf("%d", &num);

	int** arr = (int**)malloc(sizeof(int*) * num);
	for (int i = 0; i < num; i++) {
		arr[i] = (int*)malloc(sizeof(int) * num);
	}
	
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			arr[i][j] = (n += 2);
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < num; i++) {
		free(arr[i]);
	}
	free(arr);
}