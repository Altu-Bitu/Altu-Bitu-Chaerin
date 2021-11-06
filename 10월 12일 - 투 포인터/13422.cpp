//
// Created by 김채린 on 2021/11/07.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        // 입력
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> houses(n + m - 1, 0);
        for (int i = 0; i < (n + m - 1); i++) {
            if (i >= n)
                houses[i] = houses[i - n];
            else
                cin >> houses[i];
        }

        // 연속된 m개의 집 털기
        int money = 0;
        int cnt = 0;
        for (int i = 0; i < m; i++)
            money += houses[i];
        if (money < k)
            cnt++;

        // 모든 가능성 체크
        for (int i = 1; i < n; i++) {
            money = money - houses[i - 1] + houses[i + (m - 1)];
            if (money < k)
                cnt++;
        }

        // 출력
        // !!! 회전초밥 문제와 매우 유사 + 오히려 더 쉬웠으나
        // !!! n==m인 경우를 생각해내지 못함..
        // !!! 이런 코너케이스는 어떻게 떠올릴 수 있는걸까.. ㅠㅠ
        // 참고 : https://www.acmicpc.net/board/view/39541
        if (n == m) {
            if (money < k)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        } else
            cout << cnt << '\n';

    }

}