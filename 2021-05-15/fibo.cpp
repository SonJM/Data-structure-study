#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
// 한번 구한 값은 저장할 배열 공간을 만들어서 DP의 두번째 조건을 만족시켜줌으로써 계산 속도 개선
int d[100];      // 모든 배열의 값 0 으로 초기화 => 메모이제이션 기법

int function(int num) {
    if (num == 1) return 1;
    if (num == 2) return 1;
    if (d[num] != 0) return d[num];
    return d[num] = function(num - 1) + function(num - 2);        // 피보나치 수열의 점화식
                                                         // 피보나치 수열 : 특정한 숫자를 구하기 위한 그 앞에 있는 숫자와 두 칸 앞에 있는 숫자의 합
}

int main() {
    int num = 0;
    scanf("%d", &num);

    printf("fibo index :%d and result = %d\n", num, function(num));

    return 0;
}
