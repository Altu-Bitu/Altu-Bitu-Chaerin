#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> sushi(n + k - 1, 0);
    for (int i = 0; i < (n + k - 1); i++) {
        if (i >= n)
            sushi[i] = sushi[i - n];
        else
            cin >> sushi[i];
    }

    // 먹은 초밥의 총 개수
    int cnt = 0;
    // 먹은 초밥 표시 벡터
    vector<int> eat(d + 1, 0);
    // 쿠폰 초밥
    eat[c]++;
    cnt++;
    // 벨트 위 초밥
    for (int i = 0; i < k; i++) {
        if (eat[sushi[i]] == 0)
            cnt++;
        eat[sushi[i]]++;
    }

    // 모든 가능성 체크
    int max_cnt = cnt;
    for (int i = 1; i < n; i++) {
        eat[sushi[i-1]]--;
        if (eat[sushi[i-1]]==0)
            cnt--;
        eat[sushi[i+(k-1)]]++;
        if (eat[sushi[i+(k-1)]]==1)
            cnt++;
        max_cnt = max(max_cnt, cnt);
    }

    // 출력
    cout << max_cnt;

}