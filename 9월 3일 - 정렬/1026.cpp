//
// Created by 김채린 on 2021/09/09.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
vector<int> b;

int main() {

    //입력
    int n;
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    //연산
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());
    int s = 0;
    for (int i = 0; i < n; i++)
        s = s + a[i] * b[i];

    //출력
    cout << s;

}
