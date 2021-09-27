//
// Created by 김채린 on 2021/09/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // 입력
    int n, input, max_cnt;
    double sum;
    cin >> n;
    // 입력값을 저장할 벡터
    vector<int> v(n, 0);
    // 입력값의 등장 빈도를 저장할 벡터
    vector<int> v2(8001, 0);
    for (int i = 0; i < n; i++) {
        cin >> input;
        v[i] = input;
        sum += v[i];
        v2[input + 4000]++;
        if (v2[input + 4000] > max_cnt)
            max_cnt = v2[input + 4000];
    }
    sort(v.begin(), v.end());

    // 산술평균
    double avg = sum / n;
    cout << fixed;
    cout.precision(0);
    cout << avg << '\n';

    // 중앙값
    int mid = v[n / 2];
    cout << mid << '\n';

    // 최빈값
    vector<int> v3;
    for (int i = 0; i < v2.size(); i++) {
        if (v2[i] == max_cnt)
            v3.push_back(i - 4000);
    }

    sort(v3.begin(), v3.end());
    if (v3.size() == 1)
        cout << v3[0] << '\n';
    else
        cout << v3[1] << '\n';

    // 범위
    int range = v[v.size() - 1] - v[0];
    cout << range << '\n';
}