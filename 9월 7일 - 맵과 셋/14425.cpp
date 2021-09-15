//
// Created by 김채린 on 2021/09/13.
//

#include <iostream>
#include <map>

using namespace std;

int main() {
    //입력
    int n, m;
    cin >> n >> m;

    // map s에 집합 S에 포함된 문자열 입력
    string str;
    map<string, bool> s;
    for (int i = 0; i < n; i++) {
        cin >> str;
        s[str] = true;
    }

    // map s에 검사해야 하는 문자열이 포함되어있는지 확인
    int count = 0;
    for (int i = 0; i < m; i++) {
        cin >> str;
        if (s[str])
            count++;
    }

    //출력
    cout << count;
}