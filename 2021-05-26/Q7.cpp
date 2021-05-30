// 포인터
// call by address 를 이용해서 사용자 정의함수의 이름을 swap으로 해 두고, 두 변수의 값을 입력 받아 출력하시오
// 예시 입력 : 5 10		출력 : 10 5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("%d %d", a, b);
}