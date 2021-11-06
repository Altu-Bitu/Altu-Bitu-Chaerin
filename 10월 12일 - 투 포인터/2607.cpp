//
// Created by 김채린 on 2021/11/06.
//

#include <iostream>
#include <vector>

using namespace std;

bool similar(string first, string str, vector<int> first_v) {
    int length_diff = first.length() - str.length();

    if (abs(length_diff) > 1)
        return false;

    vector<int> str_v(26, 0);
    for (int i = 0; i < str.length(); i++)
        str_v[str[i] - 'A']++;

    int diff_sum = 0;
    for (int i = 0; i < 26; i++) {
        int diff = first_v[i] - str_v[i];
        if (abs(diff) > 1)
            return false;
        diff_sum += abs(diff);
    }

    if (diff_sum > 2)
        return false;

    return true;
}

int main() {

    // 입력
    int n;
    int cnt = 0;
    string first_str, str;
    cin >> n >> first_str;

    // 연산 (두번째~ 각 단어);
    vector<int> first_v(26, 0);
    for (int i = 0; i < first_str.length(); i++)
        first_v[first_str[i] - 'A']++;
    for (int i = 1; i < n; i++) {
        cin >> str;
        if (similar(first_str, str, first_v))
            cnt++;
    }

    // 출력
    cout << cnt;

}