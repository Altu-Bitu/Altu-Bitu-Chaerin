//
// Created by 김채린 on 2021/09/13.
//

#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    //입력
    int n, m;
    string str;
    cin >> n >> m;

    map<string, bool> not_heard;
    set<string> s;

    // map에 듣도 못한 사람의 명단 입력
    for (int i = 0; i < n; i++) {
        cin >> str;
        not_heard[str] = true;
    }

    // map에서 보도 못한 사람이 있는지 확인, 있으면 set에 입력
    int count = 0;
    for (int i = 0; i < m; i++) {
        cin >> str;
        if (not_heard[str]) {
            count++;
            s.insert(str);
        }
    }

    //출력
    cout << count << '\n';
    for (auto i = s.begin(); i != s.end(); i++) {
        cout << *i << '\n';
    }
}