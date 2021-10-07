//
// Created by 김채린 on 2021/10/07.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // 입력
    int n;
    cin >> n;
    vector<int> straw;
    straw.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> straw[i];

    // 연산
    sort(straw.begin(), straw.end());
    int a, b, c;
    for (int i = n - 1; i > 1; i--) {
        a = straw[i - 2];
        b = straw[i - 1];
        c = straw[i];
        if (a + b > c) {
            cout << a + b + c;
            return 0;
        }
    }

    cout << -1;
    return 0;
}
