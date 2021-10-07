//
// Created by 김채린 on 2021/10/03.
//

#include <iostream>

using namespace std;

int main() {

    // 변수
    int n;
    long long answer;

    // 입력
    cin >> n;

    // dp[i][j]에 길이가 i이고, j로 끝나는 계단수의 개수를 저장
    int dp[101][10] = {0};

    // 길이가 1일 때
    dp[1][0] = 0;
    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;

    // 길이가 2이상일 때
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][9] = dp[i - 1][8];
        for (int j = 1; j <= 8; j++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
    }

    // 연산
    answer = 0;
    for (int i = 0; i <= 9; i++) {
        answer += dp[n][i];
    }

    // 출력
    cout << answer % 1000000000;
}