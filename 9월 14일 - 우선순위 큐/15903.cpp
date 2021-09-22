//
// Created by 김채린 on 2021/09/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // 카드의 개수, 카드 합체를 몇 번 하는지
    int n, m;
    cin >> n >> m;

    // 모든 카드를 차례로 벡터 v에 저장
    long long tmp;
    vector<long long> v;
    while (n--) {
        cin >> tmp;
        v.push_back(tmp);
    }

    // m번 합치기
    while (m--) {
        sort(v.begin(), v.end());
        tmp = v[0] + v[1];
        v[0] = tmp;
        v[1] = tmp;
    }

    // 결과 출력
    long long answer = 0;
    for (int i = 0; i < v.size(); i++)
        answer += v[i];

    cout << answer;
}
