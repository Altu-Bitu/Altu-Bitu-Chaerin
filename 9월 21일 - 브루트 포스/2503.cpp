//
// Created by 김채린 on 2021/09/27.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// s1 : 추측, s2 : 정답일 때, strike값을 반환하는 함수
int countStrike(string s1, string s2) {
    // strike값을 저장할 변수
    int strike = 0;
    // 세 자리를 하나씩 확인
    for (int i = 0; i < 3; i++) {
        // 같은 자리에 같은 값이 있으면 strike값 +1
        if (s1[i] == s2[i])
            strike++;
    }
    // strike값 반환
    return strike;
}


// s1 : 추측, s2 : 정답일 때, ball값을 반환하는 함수
int countBall(string s1, string s2) {
    // ball값을 저장할 변수
    int ball = 0;
    // s1의 세 자리를 하나씩 확인
    for (int i = 0; i < 3; i++) {
        // s1의 각 자리와 s2의 세 자리를 차례로 비교
        for (int j = 0; j < 3; j++) {
            // 같은 자리끼리는 그냥 넘어가기
            if (i == j) continue;
            // 다른 자리끼리 비교할 때, 같은 수가 있으면
            if (s1[i] == s2[j]) {
                // 중복 카운트를 방지하기 위해 ball++ 후 break
                ball++;
                break;
            }
        }
    }
    // ball값 반환
    return ball;
}

int main() {

    // 변수
    // n : 추측 시도 횟수
    // strike : 각 추측의 strike값을 저장할 변수
    // ball : 각 추측의 ball값을 저장할 변수
    // guess : 추측한 숫자를 문자열로 저장할 변수
    int n, strike, ball;
    string guess;

    // 입력
    cin >> n;

    // 인덱스값이 답이 될 수 있으면 1, 그렇지 않으면 0을 저장할 벡터
    // 1로 초기화해두고 조건을 만족하지 않는 숫자들을 인덱스로 하는 값을 0으로 바꿀 예정
    vector<int> v(988, 1);

    // n번의 추측 시도
    for (int i = 0; i < n; i++) {
        // 입력
        cin >> guess >> strike >> ball;

        // Strike 연산
        // 서로 다른 세 자리 수이므로 123~987을 하나씩 모두 검사해서 가능한 정답 추리기
        for (int i = 123; i <= 987; i++) {
            // 정답 후보를 문자열로 저장할 변수
            string answer = to_string(i);
            // 0이 하나라도 있으면
            if (answer[0] == '0' || answer[1] == '0' || answer[2] == '0') {
                // 정답일 수 없으므로 0으로 바꿈
                v[i] = 0;
                // 정답일 수 없으므로 다음 수로 넘어감
                continue;
            }
            // 서로 같은 수가 하나라도 있으면
            if (answer[0] == answer[1] || answer[0] == answer[2] || answer[1] == answer[2]) {
                // 정답일 수 없으므로 0으로 바꿈
                v[i] = 0;
                // 정답일 수 없으므로 다음 수로 넘어감
                continue;
            }
            // 추측의 strike값이나 ball값 중 하나라도 맞지 않으면
            if (countStrike(guess, answer) != strike || countBall(guess, answer) != ball) {
                // 정답일 수 없으므로 0으로 바꿈
                v[i] = 0;
            }
        }
    }

    // 가능한 정답의 개수를 저장할 변수
    int result = 0;
    // v를 순회하며
    for (int i = 123; i <= 987; i++) {
        // 저장된 값이 1일 경우
        if (v[i] == 1) {
            // 정답의 개수 +1
            result++;
        }
    }
    // 가능한 정답의 개수 출력
    cout << result;
}