//
// Created by 김채린 on 2021/09/23.
//

#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    int answer = n;
    for (int i = n - 1; i >= 1; i--) {
        answer *= i;
    }
    return answer;
}

int main() {

    // 입력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;

    // 연산
    int answer = factorial(n) / (factorial(k) * factorial(n - k));

    // 출력
    cout << answer;
}