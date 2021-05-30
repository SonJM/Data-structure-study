// 이중for문을 이용해서 엑스박스 그리기 (단, 이중 for문은 5x5 행렬로 구현한다.)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int num;
	scanf("%d", &num);	// 반복 횟수 지정

	char** arr = (char**)malloc(sizeof(char*) * num);	// 2차원 배열 동적 할당
	
	for (int i = 0; i < num; i++) {
		arr[i] = (char*)malloc(sizeof(char) * num);		// 2차원 배열 동적 할당
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (i == j || i + j == num-1) arr[i][j] = '*';
			else if (i == 0 || j == 0 || i == num-1 || j == num-1) arr[i][j] = '*';
			else arr[i][j] = ' ';														// arr[i][j]에 원하는 모양의 별 모양 입력
		}
	}
	
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			printf("%c", arr[i][j]);				// 이중 for문을 통한 2차원 배열 출력
		}
		printf("\n");
	}

	for (int i = 0; i < num; i++) {
		free(arr[i]);								// 2차원 배열 메모리 반환
	}
	free(arr);

	return 0;

}