//
// Created by 김채린 on 2021/10/03.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    // 변수
    int n, input_a, input_b, result;

    // 입력
    cin >> n;

    // 전깃줄의 상태를 저장할 배열
    vector<pair<int, int>> v;
    v.assign(n + 1, {});
    for (int i = 1; i <= n; i++) {
        cin >> input_a >> input_b;
        v[i] = make_pair(input_a, input_b);
    }

    // 가장 긴 증가하는 부분수열을 찾는 것과 같은 문제!!!
    // 둘 중 한 전봇대 기준으로 정렬한 후 나머지 전봇대에서 가장 긴 증가하는 부분수열을 찾으면
    // 그 수열에 해당하지 않는 전깃줄만 제거하면 된다!

    // 정렬
    sort(v.begin(), v.end());

    // DP배열
    int dp[101] = {0};
    dp[1] = 1;

    // 연산
    for (int i = 2; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (v[j].second < v[i].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    result = 0;
    for (int i = 1; i <= n; i++)
        result = max(dp[i], result);

    // 출력
    cout << n - result;

}