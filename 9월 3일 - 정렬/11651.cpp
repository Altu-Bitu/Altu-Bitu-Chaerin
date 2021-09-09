//
// Created by 김채린 on 2021/09/09.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct dot {
    int x, y;
};

bool cmp(const dot &i1, const dot &i2) {
    if (i1.y != i2.y) //y좌표가 다르다면 증가하는 순서
        return i1.y < i2.y;
    return i1.x < i2.x; //x좌표가 증가하는 순서
}

int main() {
    int n;
    vector<dot> arr;

    //입력
    cin >> n;
    arr.assign(n, {});
    for (int i = 0; i < n; i++)
        cin >> arr[i].x >> arr[i].y;

    //연산
    sort(arr.begin(), arr.end(), cmp);

    //출력
    for (int i = 0; i < n; i++)
        cout << arr[i].x << ' ' << arr[i].y << '\n';
}
