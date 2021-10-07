//
// Created by 김채린 on 2021/10/07.
//

#include <iostream>
#include <vector>

#define MAX 1000000001

using namespace std;

int main() {

    // 입력
    int n;
    cin >> n;
    // i번째 도시와 i+1번째 도시를 연결하는 도로의 길이를 저장할 벡터
    vector<long long> road;
    road.assign(n, 0);
    for (int i = 1; i <= n - 1; i++)
        cin >> road[i];
    // i번째 도시에 있는 주유소의 리터당 가격을 저장할 벡터
    vector<long long> oil;
    oil.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> oil[i];

    // 연산
    long long min_oil = MAX;
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        min_oil = min(oil[i], min_oil);
        // !!! 이 문제를 처음 풀 때는 ans만 long long으로 변경하면 된다고 생각했으나
        // !!! 자료형에 대해 검색한 결과 int와 int를 곱한 값이 int의 범위를 넘어가는 경우
        // !!! long long으로 넘겨주기 전, int와 int를 곱하는 그 순간에
        // !!! 이미 오버플로우가 발생한다고 한다.
        ans += min_oil * road[i];

    }

    cout << ans;

}