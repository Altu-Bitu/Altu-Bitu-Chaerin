//
// Created by 김채린 on 2021/09/09.
//

#include <iostream>
#include <vector>

using namespace std;

//각 시험장의 응시자 수 배열
vector<int> arr;

int main() {

    int n;  //시험장의 개수
    int b;  //총감독관이 한 시험장에서 감시할 수 있는 응시자의 수
    int c;  //부감독관이 한 시험장에서 감시할 수 있는 응시자의 수

    //입력
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> b;
    cin >> c;

    //연산
    long long result = 0;
    for (int i = 0; i < n; i++) {
        result++;   //모든 시험장마다 한 명의 총감독관 필요
        int rest = 0;   //부감독관이 감시해야 하는 응시자의 수
        int d = 0;  //각 시험장별로 필요한 부감독관 수
        rest = arr[i] - b;
        if (rest > 0) {
            d = rest / c;
            if (rest % c != 0)
                d++;
        }
        result = result + d;
    }

    //출력
    cout << result;
}