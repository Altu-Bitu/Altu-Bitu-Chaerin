//
// Created by 김채린 on 2021/09/16.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    //입력
    int n;
    string str;
    cin >> n >> str;
    vector<double> num;
    num.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> num[i];

    //연산
    stack<double> s;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            double a, b;
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            switch (c) {
                case '+':
                    s.push(a + b);
                    break;
                case '-':
                    s.push(a - b);
                    break;
                case '*':
                    s.push(a * b);
                    break;
                case '/':
                    s.push(a / b);
                    break;
            }
        } else {
            s.push(num[str[i] - 65]);
        }
    }

    //출력
    cout << fixed;
    cout.precision(2);
    cout << s.top();
}