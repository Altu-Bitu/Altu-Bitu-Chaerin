//
// Created by 김채린 on 2021/09/09.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct score {
    int document;
    int interview;
};

vector<int> result;
vector<score> arr;

bool cmp(const score &i1, const score &i2) {
    return i1.document < i2.document;
}

int cnt(int n) {
    int sum = n;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i].interview > arr[j].interview) {
                sum--;
                break;
            }
        }
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    result.assign(t, 0);
    for (int i = 0; i < t; i++) {    // 각 테스트케이스
        int n;
        cin >> n;
        arr.assign(n, {});
        for (int j = 0; j < n; j++) {    //각 면접자
            cin >> arr[j].document >> arr[j].interview;
        }
        sort(arr.begin(), arr.end(), cmp);    //서류심사성적순으로 정렬
        result[i] = cnt(n);
    }

    //출력
    for (int i = 0; i < t; i++)
        cout << result[i] << '\n';
}
