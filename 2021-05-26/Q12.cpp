// 7개의 자연수가 주어질 때, 이들 중에서 홀수로서 가장 큰 수와 짝수로서 가장 큰 수를 각각 찾아 그 합을 구하는 프로그램을 작성하시오.

#define _CRT_SECURE_NO_WARNINGS
#define LENGTH 7
#include <stdio.h>

int main() {
	int arr[LENGTH];
	int temp;

	for (int i = 0; i < LENGTH; i++) {
 		scanf("%d", arr + i);
	}
	// Bubble Sort
	for (int i = 0; i < LENGTH - 1; i++) {	// 맨 끝에 것은 선택해도 그 다음과 비교할것 없으므로 선택필요x
		for (int j = 0; j < LENGTH - 1 - i; j++) {	// 비교는 0부터 시작해야 하므로
			if (*(arr + j) > *(arr + j + 1)) {
				//앞에것이 크면 swap
				temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}

	if (arr[6] % 2 == 0 && arr[5] % 2 == 0) printf("%d", arr[6]);
	else if (arr[6] % 2 == 1 && arr[5] % 2 == 1) printf("%d", arr[6]);
	else printf("%d", arr[5] + arr[6]);
}