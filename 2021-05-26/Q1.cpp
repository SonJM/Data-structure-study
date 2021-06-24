// for문을 이용해서 등비수열 합 구현하기	
// 초항: 1	공비: 3	총합: 1~6번항 까지의 합
// 입력: 1 3		출력: 1093

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>		// pow 멤버 함수 사용하기 위해 호출

int main() {
	int a, b;
	int sum = 0;
	scanf("%d %d", &a, &b);
	for (int i = 0; i < 7; i++) {
		sum += a * pow(b, i);	
									// 등비수열의 합: a + ar + ar^2 + ar^3 + ...
									// C에서의 pow함수 원형 -> double pow(double base, double n) -> base에 n을 제곱한 값 반환
									/*	C++에서의 pow함수 원형
										1. double        pow(double base, double n)
										2. float           pow(float base, float n)
										3. long double pow(long double base, long double n)*/
	}
	printf("%d \n", sum);
}