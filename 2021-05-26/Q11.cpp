// 동적할당
// 동적할당 배열로 stack 과 queue를 구현하려고 한다. 조건은 다음과 같다.

/*1. 동적할당으로 배열을 만든 후, 임의의 값을 넣는다.
	2. 홀수이면 stack에 , 짝수이면 queue에 넣으려고 한다.
	3. stack 과 queue 역시 동적할당으로 만든 배열안에 구현하며, 위의 2번조건은 반드시 만족시켜야 한다.
	4. stack 출력 , queue 출력을 반복한다. (단, stack 또는 queue의 출력이 끝나면 그 이후에는 stack 과 queue 배열 중 값을 다 출력하지 않은 배열을 그대로 쭉 출력한다.*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int num, i = 0;
	int a = 0, b = 0;

	scanf("%d", &num);

	int* arr = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++) {
		scanf("%d", arr + i);
	}

	int stack[100];	int queue[100];

	for (i = 0; i < num; i++) {
		if (arr[i] % 2 == 1) {
			stack[a] = arr[i];
			a++;
		}
		if (arr[i] % 2 == 0) {
			queue[b] = arr[i];
			b++;
		}
	}

	for (i = 0; i < num/2; i++) {
		if (*(stack + i) == NULL || *(queue + i) == NULL) break;
		printf("%d ", *(stack + i));
		printf("%d ", *(queue + i));
	}

	free(arr);
}