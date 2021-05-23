#include <iostream>

using namespace std;
// 입력 받는 매개 변수 a b에서 큰 수에서 작은 수가 나누어 떨어질 경우엔 큰 수 출력
// 아닐 경우엔 a * b 출력 => a, b의 최소공배수 구하는 식
int function1(int a, int b) {
    if (b == 0) return a;
    else {
        return function1(b, a % b);         // function1의 재귀함수 -> 나머지가 0이 될 때까지 실행
    }
}

int main() {
    ios_base::sync_with_stdio(false);       // c의 stdio와 cpp의 iostram의 동기화를 비활성화 시킨다.
                                            // 왜? -> ios_base::sync_with_stdio 구문은 stdio와 iotream을 동기화 시켜주는데
                                            //        이 때 iostram과 stdio의 버퍼를 모두 사용하기 때문에 딜레이가 발생한다. 이를 막기 위함'
                                            // c++만의 독립적인 버퍼가 생성되어 c의 버퍼와 병행하여 사용 X -> 실행 속도가 빨라진다
    cin.tie(NULL);                          // cin과 cout의 묶음을 풀어준다,,?
                                            // 속도 향상을 위해 입력과 출력을 번갈아서 반복해야 하는 경우 필수적이다

    int N, A, B, k;
    cin >> N;   // 반복 횟수
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        k = function1(B, A);                // 경우의 수 찾기 : k가 1이 아닐 경우가 있을까? -> 두 수가 딱 나누어 떨어질 경우!!!!!
        cout << k * (A / k) * (B / k) << '\n';      //  입력받은 두 수 A와 B의 최소공배수를 구하는 식이다
    }
}