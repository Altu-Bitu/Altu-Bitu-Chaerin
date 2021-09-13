//
// Created by 김채린 on 2021/09/09.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct people {
    int time_withdraw;
    int time_wait;
};

vector<people> arr;

bool cmp(const people &i1, const people &i2) {
    return i1.time_withdraw < i2.time_withdraw; //인출하는데 시간이 적게 걸리는 사람부터 정렬
}

int main() {

    //입력
    int n;
    cin >> n;
    arr.assign(n, {});
    for (int i = 0; i < n; i++)
        cin >> arr[i].time_withdraw;

    //정렬
    sort(arr.begin(), arr.end(), cmp);

    //출력
    for (int i = 0; i < n; i++) {
        arr[i].time_wait = arr[i].time_withdraw;
        for (int j = 0; j < i; j++)
            arr[i].time_wait = arr[i].time_wait + arr[j].time_withdraw;
    }

    int result = 0;
    for (int i = 0; i < n; i++)
        result = result + arr[i].time_wait;

    cout << result;

}
