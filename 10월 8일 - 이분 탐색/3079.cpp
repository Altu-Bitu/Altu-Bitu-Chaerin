//
// Created by 김채린 on 2021/10/13.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> t;

// 시간이 time만큼 있을 때, 입국심사가 가능한 사람 수를 반환하는 함수
long long cntPpl(long long time) {
    long long cnt = 0;
    for (long long i = 0; i < t.size(); i++)
        cnt += time/t[i];
    return cnt;
}

// lower search
long long lowerSearch(long long left, long long right, int target) {
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long cnt = cntPpl(mid);
        if (cnt >= target)
            right = mid - 1;
        else if (cnt < target)
            left = mid + 1;
    }
    return right + 1;
}

int main() {

    // 입력
    int n, m;
    cin >> n >> m;
    t.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> t[i];

    // 소요 시간 최댓값
    long long max_time = *max_element(t.begin(), t.end()) * m;

    // 연산 & 출력
    long long answer = lowerSearch(1, max_time, m);
    cout << answer;

    return 0;

}