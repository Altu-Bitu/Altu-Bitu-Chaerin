//
// Created by 김채린 on 2021/09/27.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countStrike(string s1, string s2) {
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        if (s1[i] == s2[i])
            cnt++;
    }
    return cnt;
}

int countChar(string s, char c) {
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        if (s[i] == c)
            cnt++;
    }
    return cnt;
}

int countBall(string s1, string s2) {
    // s1 : 추측, s2 : 정답
    int max = 0;
    for (int i = 0; i < 3; i++) {
        if (countChar(s2, s1[i])>max){
            max = countChar(s2, s1[i]);
        }
    }
    return max;
}

int main() {

    int n, strike, ball;
    cin >> n;
    string guess;
    // 인덱스값이 답이 될 수 있으면 1, 그렇지 않으면 0을 저장할 벡터
    vector<int> v(1000, 1);

    for (int i = 0; i < n; i++) {

        // 입력
        cin >> guess >> strike >> ball;

        // Strike 연산
        for (int i = 111; i < 1000; i++) {
            string answer = to_string(i);
            if (countStrike(guess, answer) != strike) {
                v[i] = 0;
            }
        }

        // Ball 연산
        for (int i = 111; i < 1000; i++) {
            string answer = to_string(i);
            if (countBall(guess, answer) != ball) {
                v[i] = 0;
            }
        }
    }

    for (int i = 111; i < 1000; i++)
        cout << i << " : " << v[i] << '\n';

//    // 출력
//    int result = 0;
//    for (int i = 111; i < 1000; i++) {
//        if (v[i] == 1) {
//            cout << "i : " << i << ' ';
//            result++;
//        }
//    }
//    cout << result;
}