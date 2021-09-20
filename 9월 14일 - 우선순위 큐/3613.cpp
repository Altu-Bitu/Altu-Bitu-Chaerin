//
// Created by 김채린 on 2021/09/20.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    string new_str = "";
    cin >> str;
    bool is_c_or_java = true;


    if ((str[0] >= 'A' && str[0] <= 'Z') || str[0] == '_' || str[str.length() - 1] == '_' || str.find("__") != -1) {
        is_c_or_java = false;
    }
    if (str.find('_') != -1) {
        for (int i = 0; i < str.length(); i++) {
            if ((str[i] >= 'A' && str[i] <= 'Z'))
                is_c_or_java = false;
        }
    }

    // 주어진 변수명이 c++ 형식도 java 형식도 아니라면
    if (!is_c_or_java)
        cout << "Error!";

        // 주어진 변수명이 c++ 형식이라면
    else if (str.find('_') != -1) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '_') {
                new_str += toupper(str[i + 1]);
                i++;
            } else
                new_str += str[i];
        }
        cout << new_str;
    }

        // 주어진 변수명이 java 형식이라면
    else {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                new_str += '_';
                new_str += tolower(str[i]);
            } else
                new_str += str[i];
        }
        cout << new_str;

    }
}
