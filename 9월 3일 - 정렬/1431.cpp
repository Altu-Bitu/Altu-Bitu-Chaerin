//
// Created by 김채린 on 2021/09/09.
//

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

struct serial {
    string str;
    int sum;
};

vector<serial> arr;

//비교함수
bool cmp(const serial &i1, const serial &i2) {
    if (i1.str.length() != i2.str.length()) //두 문자열의 길이가 다르다면 짧은 것이 먼저
        return i1.str.length() < i2.str.length();
    if (i1.sum != i2.sum) //모든 정수의 합이 다르다면 합이 작은 것이 먼저
        return i1.sum < i2.sum;
    return i1.str < i2.str; //사전순 비교
}

int main() {

    //입력
    int n;
    cin >> n;
    arr.assign(n, {});
    for (int i = 0; i < n; i++) {
        cin >> arr[i].str;
        for (int j = 0; j < arr[i].str.length(); j++) {
            if (isdigit(arr[i].str[j])) {
                char c = arr[i].str[j];
                int d = c - '0';
                arr[i].sum = arr[i].sum + d;
            }
        }
    }

    //정렬
    sort(arr.begin(), arr.end(), cmp);

    //출력
    for (int i = 0; i < n; i++)
        cout << arr[i].str << '\n';

}
