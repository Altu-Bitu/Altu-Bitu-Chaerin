//
// Created by 김채린 on 2021/10/07.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 10이 배수인 것이 앞으로
// 10의 배수인 것들 끼리는 크기가 작은 것이 앞으로
bool compare(int a, int b) {
    if (a % 10 == 0 && b % 10 != 0)
        return true;
    if (a % 10 != 0 && b % 10 == 0)
        return false;
    if (a % 10 == 0 && b % 10 == 0)
        return a < b;
}

int main() {

    // 입력
    int n, m;
    cin >> n >> m;
    vector<int> rollcakes;
    rollcakes.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> rollcakes[i];

    // 연산
    sort(rollcakes.begin(), rollcakes.end(), compare);
    int answer = 0;
    int i = 0;
    while (m != 0 && i < n) {
        if (rollcakes[i] < 10) {
            i++;
            continue;
        }
        if (rollcakes[i] == 10) {
            answer++;
            i++;
            continue;
        }
        if (rollcakes[i] == 20) {
            answer += 2;
            i++;
            m--;
            continue;
        }
        rollcakes[i] -= 10;
        answer++;
        m--;
    }

    // 출력
    cout << answer;

}