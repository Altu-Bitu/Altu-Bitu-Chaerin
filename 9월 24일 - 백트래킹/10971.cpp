//
// Created by 김채린 on 2021/09/30.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 10;

int n, sum;
int w[SIZE][SIZE];
int num[SIZE]; // 수열
int check[SIZE]; // 수 사용 체크 배열
vector<int> v;

// 재귀함수로 구현한 백트래킹
void backtracking(int cnt) {
    if (cnt == n) { // 기저조건
        sum = 0;
        for (int i = 1; i < cnt; i++) {
            if (w[num[i - 1]][num[i]] == 0)
                return;
            else
                sum += w[num[i - 1]][num[i]];
        }
        if (w[num[cnt-1]][num[0]] == 0)
            return;
        sum += w[num[cnt-1]][num[0]];
        v.push_back(sum);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!check[i]) { // 현재 수열에 해당 수가 없어야 사용 가능
            num[cnt] = i; // 수열에 값 저장
            check[i] = true; // 수 사용
            backtracking(cnt + 1); // 다음 수열 인덱스 호출
            check[i] = false; // 원래 상태로 돌려놓음
        }
    }
}

int main() {

    // 입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    // 연산
    backtracking(0);

    // 출력
    sort(v.begin(), v.end());
    cout << v[0] << '\n';

    return 0;
}