#include <iostream>

using namespace std;

int function1(int a, int b) {
    if (b == 0) return a;
    else {
        return function1(b, a % b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, A, B, k;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        k = function1(B, A);
        cout << k * (A / k) * (B / k) << endl;
    }
}