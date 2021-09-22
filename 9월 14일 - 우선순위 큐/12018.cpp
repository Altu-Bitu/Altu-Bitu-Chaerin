//
// Created by 김채린 on 2021/09/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // 과목 수, 주어진 마일리지
    int n, m;
    int answer = 0;
    cin >> n >> m;

    // 성준이가 각 과목에 투자할 최소 마일리지
    vector<int> v;
    // 각 과목별로 사람들이 마일리지를 얼마나 넣었는지 임시로 저장
    vector<int> m_vec;

    // 각 과목마다
    while (n--) {
        // 신청한 사람 수, 수강인원
        int p, l;
        cin >> p >> l;
        int tmp;

        if (p < l) {
            while (p--)
                cin >> tmp;
            v.push_back(1);
        } else {
            m_vec.clear();
            while (p--) {
                cin >> tmp;
                m_vec.push_back(tmp);
            }
            sort(m_vec.begin(), m_vec.end(), greater<>());
            v.push_back(m_vec[l - 1]);
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        m -= v[i];
        if (m < 0) break;
        answer++;
    }

    cout << answer;

}