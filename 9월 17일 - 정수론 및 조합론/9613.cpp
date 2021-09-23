//
// Created by 김채린 on 2021/09/23.
//

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    // 각 테스트케이스
    while (t--) {
        int n, input;
        long long answer;
        cin >> n;

        vector<int> v;

        answer = 0;
        for (int i = 0; i < n; i++) {
            input;
            cin >> input;
            v.push_back(input);
            if (i == 0) continue;
            for (int j = 0; j < i; j++)
                answer += gcd(max(v[i], v[j]), min(v[i], v[j]));
        }

        cout << answer << '\n';

    }
}