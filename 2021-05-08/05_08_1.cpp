#include <stdio.h>
#include <stdlib.h>

//에라토스테네스의 체 : 대량의 숫자가 소수인지 판별하기 위한 알고리즘
#define MAX 1001    // MAX라는 매크로 상수명을 매크로 확장 문자열 1001로 치환

void eratos(int* arr);

int main(int argc, char** argv) {       // int argc : main함수에 전달되는 정보의 갯수
                                        // char** argv : main함수에 실질적으로 전달되는 정보의 더블포인터
    int num = 1;
    int* arr = (int*)malloc(sizeof(int) * MAX);     // malloc을 이용한 동적 할당 포인터
                                                        // void* malloc(size_t size)
                                                        // size_t size -> 할당할 메모리의 크기 선정 : sizeof(int) * MAX = 4 * 1000 = 4004(byte)
                                                        // int* : 반환형이 int형 포인터 (강제 형변환)
                                                    // malloc, free vs new, delete -> 생성자, 소멸자의 자동 호출
    
    for (int i = 2; i < MAX; i++) {
        arr[i] = i;                                 // arr[] 배열은 2~1000까지의 숫자가 입력된 '동적' 배열
    }

    eratos(arr);

    free(arr);      // arr에 할당된 메모리 해제 (반환)
    return 0;
}

void eratos(int* arr) {
    for (int i = 2; i < MAX; i++) {     // i번 칸의 데이터가 0일때 continue
        if (arr[i] == 0) continue;

        for (int j = i * i; j < MAX; j += i)// i의 배수의 값 = 0 -> n의 배수는 소수가 아니기 문에 0 대입
            arr[j] = 0;
        }
    }

    printf("소수찾기\n");
    for (int i = 2; i < MAX; i++) {
        if (arr[i] != 0) printf("%d ", arr[i]);     // 소수의 값만 출력
    }
}
