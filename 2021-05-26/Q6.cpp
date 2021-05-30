// 사용자 정의 함수
// 피보나치 수열 10번째 항을 출력하는 프로그램을 사용자 정의 함수를 이용해서 만드시오

#include <stdio.h>

int d[10];

int fibo(int n) {
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (d[n] != 0) return d[n];
	return d[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
	printf("%d", fibo(10));
	return 0;
}