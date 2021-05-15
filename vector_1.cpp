#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b);
int binsearch(vector<int> v, int key);

int main() {
    int index;
    int key;
    int findNum;

    vector<int> v;

    printf("insert key(if key = 0 : break)\n");
    while (1) {
        scanf("%d", &key);
        if (key == 0) break;
        v.push_back(key);       
    }// 마지막 위치에 key 값 추가
    sort(v.begin(), v.end(), compare);      // v vertor를 compare 함수 기준으로 정렬
    v.erase(unique(v.begin(), v.end()), v.end());   // 중복되는 값 제거
    cout << endl;
    cout << "show. sort vector" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << "v[" << i << "] = " << v[i] << " ";
    }

    cout << endl;

    do {

        printf("find num(if num = 0 :break)\n");
        scanf("%d", &findNum);
        index = binsearch(v, findNum);      // 찾으려는 원소의 index값

        if (findNum != 0) {
            if (index == -1) {
                printf("not found!\n");
            }
            else {
                printf("find index : %d\n", index);
            }
        }

    } while (findNum != 0);
    v.clear();      // 모든 값 제거
    printf("clear program\n");

    return 0;
}

bool compare(int a, int b) {
    return a < b;
}

int binsearch(vector<int> v, int key) {             // key(원소)값을 매개 변수로 받아서 v vector내의 index값을 반환받는 함수
    int low, high;
    int mid;

    low = 0;
    high = v.size();        // .size 원소 갯수
    while (low <= high) {
        mid = (low + high) / 2;
        if (key == v[mid]) {                        // 중앙 index값부터 비교를 해가며 key값 비교 => sort를 통해 정렬이 되어있으므로 위아래로 자유롭게 움직일 수 있음.
            return mid;
        }
        else if (key < v[mid]) {
            high = mid - 1;
        }
        else if (key > v[mid]) {
            low = mid + 1;
        }
    }
    return -1;
}