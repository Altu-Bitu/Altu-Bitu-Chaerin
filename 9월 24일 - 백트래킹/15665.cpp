//
// Created by 김채린 on 2021/09/30.
//

#include <iostream>
#include <set>

using namespace std;

const int SIZE = 8;

int n, m;
set<int> num_set;
int num[SIZE]; // 수열

// 재귀함수로 구현한 백트래킹
void backtracking(int cnt) {
    if (cnt == m) { // 기저조건
        for (int i = 0; i < cnt; i++)
            cout << num[i] << ' ';
        cout << '\n';
        return;
    }
    for (int iter : num_set) {
        num[cnt] = iter; // 수열 저장
        backtracking(cnt + 1); // 호출
    }
}

int main() {

    // 입력
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        num_set.insert(input);
    }

    // 연산 + 출력
    backtracking(0);

    return 0;
}