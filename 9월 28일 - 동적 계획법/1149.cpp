//
// Created by 김채린 on 2021/10/03.
//

#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b, int c) {
    if (a <= b) {
        if (a <= c)
            return a;
        else
            return c;
    } else {
        if (b <= c)
            return b;
        else
            return c;
    }
}

int main() {

    // 변수
    int n;

    // 입력
    cin >> n;

    // 각 집을 칠하는 비용을 저장할 배열
    int arr[1001][3] = {0};
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];
    }

    // index번째에 R/G/B집을 칠하는 최소 비용을 저장할 배열
    int dp[1001][3] = {0};

    // n=1
    dp[1][0] = arr[1][0];
    dp[1][1] = arr[1][1];
    dp[1][2] = arr[1][2];

    // n>=2
    for (int i = 2; i < n + 1; i++) {
        dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << min(dp[n][0], dp[n][1], dp[n][2]);

}