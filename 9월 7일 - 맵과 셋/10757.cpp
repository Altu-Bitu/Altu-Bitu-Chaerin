//
// Created by 김채린 on 2021/09/13.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string a, b, result;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if (a.length() < b.length()) {
        swap(a, b);
    }

    int tmp;
    int carry = 0;
    for (int i = 0; i < b.length(); i++) {
        tmp = (a[i] - '0') + (b[i] - '0') + carry;
        carry = 0;
        if (tmp > 9) {
            tmp = tmp % 10;
            carry = 1;
        }
        result[i] = char(tmp + '0');
    }

    if (a.length() == b.length()) {
        if (carry)
            result[a.length()] = '1';
    } else {
        for (int i = b.length(); i < a.length(); i++) {
            result[i] = (carry + a[i]) + '0';
        }
        if (carry)
            result[a.length()] = '1';
    }

    for (int i = a.length(); i >= 0; i--) {
        if (result[i] == NULL)
            continue;
        cout << result[i];
    }

}