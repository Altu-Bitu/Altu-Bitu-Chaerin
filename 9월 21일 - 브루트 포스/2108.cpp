//
// Created by 김채린 on 2021/09/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    // 변수
    // n : 수의 개수
    int n;
    // max_cnt : 역대 최대 등장 빈도
    int max_cnt = 0;
    // sum : 평균을 구하기 위한 수의 합
    double sum = 0;

    // 입력
    cin >> n;
    // 입력값을 저장할 벡터
    vector<int> v(n, 0);
    // 입력값의 등장 빈도를 저장할 벡터 (-4000 ~ 4000)
    vector<int> v2(8001, 0);

    // n번 반복
    for (int i = 0; i < n; i++) {
        // 입력값을 받아서 v벡터 채우기
        cin >> v[i];
        // 입력값을 sum에 더해주기
        sum += (double) v[i];
        // v2에 입력값의 등장 빈도 +1
        v2[v[i] + 4000]++;
        // 등장 빈도가 역대 최대 등장 빈도보다 커진다면 역대 최대 등장 빈도 갱신
        if (v2[v[i] + 4000] > max_cnt)
            max_cnt = v2[v[i] + 4000];
    }

    // v벡터 오름차순 정렬
    sort(v.begin(), v.end());

    // 산술평균 출력 (소수점 이하 첫째 자리에서 반올림)
    cout << round(sum / n) << '\n';

    // 중앙값 출력
    cout << v[n / 2] << '\n';

    // 최빈값들을 저장할 벡터
    vector<int> v3;
    // v2에서 등장 빈도가 역대 최대 등장 빈도와 같은 수를 찾아 v3에 저장
    for (int i = 0; i < v2.size(); i++) {
        if (v2[i] == max_cnt)
            v3.push_back(i - 4000);
    }
    // 두 번째로 작은 값을 찾기 위해 v3를 오름차순 정렬
    sort(v3.begin(), v3.end());
    // 만약 최빈값이 단 하나라면 그 값 출력
    if (v3.size() == 1)
        cout << v3[0] << '\n';
    // 최빈값이 하나 이상이라면 두 번째로 작은 값 출력
    else
        cout << v3[1] << '\n';

    // 범위 출력
    cout << v[v.size() - 1] - v[0] << '\n';
}