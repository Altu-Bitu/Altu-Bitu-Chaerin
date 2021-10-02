//
// Created by 김채린 on 2021/09/30.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 10;

int k;
string str;
vector<char> v_char;
vector<string> v_num;
int num[SIZE]; // 수열
int check[SIZE]; // 수 사용 체크 배열

// 재귀함수로 구현한 백트래킹
void backtracking(int cnt) {
    if (cnt == v_char.size() + 1) { // 기저조건
        for (int i = 0; i < cnt - 1; i++) {
            if (v_char[i] == '<') {
                if (num[i] > num[i + 1])
                    return;
            } else {
                if (num[i] < num[i + 1])
                    return;
            }
        }
        str = "";
        for (int i = 0; i < cnt; i++)
            str += to_string(num[i]);
        v_num.push_back(str);
        return;
    }
    for (int i = 0; i <= 9; i++) {
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
    cin >> k;
    char input;
    for (int i = 0; i < k; i++) {
        cin >> input;
        v_char.push_back(input);
    }

    // 연산
    backtracking(0);

    // 출력
    sort(v_num.begin(), v_num.end());
    cout << v_num[v_num.size() - 1] << '\n' << v_num[0];

    return 0;
}