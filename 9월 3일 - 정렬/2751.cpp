//
// Created by 김채린 on 2021/09/09.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//정렬할 배열, 정렬한 배열
vector<int> arr, sorted;

int main() {
    int n;

    //입력
    cin >> n;
    arr.assign(n, 0);
    sorted.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //연산
    sort(arr.begin(), arr.end());

    //출력
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}
