// 사용자 정의 함수
// 사용자 정의 함수를 구현하여, 1에서 20까지의 합을 리턴하여 값을 출력하라

#include <stdio.h>

int function(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}

int main() {
	printf("%d\n", function(20));
	return 0;
}