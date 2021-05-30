// 사용자 정의 함수
// 1~50까지의 홀수의 합을 사용자 정의함수를 이용하여 구현 해 보시오.

#include <stdio.h>

int function(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i+=2) {
		sum += i;
	}
	return sum;
}

int main() {
	printf("%d\n", function(50));
	return 0;
}