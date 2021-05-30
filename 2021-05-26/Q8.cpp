// 포인터
// 포인터 변수 ptr 로 int 타입의 num 변수를 참조하여, ptr 값을 출력하시오. (단, 메모리값이 나오면 안됩니다.
// 예시 - 12 가 나와야하는데, 14023808 이런식으로 나오면 안됩니다.)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num;
	int* ptr = &num;

	scanf("%d", &num);
	printf("ptr -> %d", *ptr);
}