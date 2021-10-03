//
// Created by 김채린 on 2021/10/03.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


int main() {

    // 변수
    int n, k, input1, input2, l, direction, cnt;
    char input_char;

    // 보드의 크기, 사과의 개수 입력
    cin >> n >> k;

    // 보드 상태를 저장할 배열 (2: 사과, 1: 뱀: 0: 아무것도 없음)
    int board[n + 1][n + 1];

    // 보드 상태를 저장할 배열 0으로 초기화
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++)
            board[i][j] = 0;
    }

    // 보드에 사과(2) 위치 저장
    while (k--) {
        cin >> input1 >> input2;
        board[input1][input2] = 2;
    }

    // 방향 변환 횟수 입력
    cin >> l;

    // 방향 전환 정보를 저장할 벡터
    vector<pair<int, char>> move;
    while (l--) {
        cin >> input1 >> input_char;
        move.push_back(make_pair(input1, input_char));
    }

    // 뱀이 있는 위치를 저장할 deque (front : 머리, back : 꼬리)
    deque<pair<int, int>> snake;

    // 시작할 때 뱀은 맨 위 맨 좌측(1,1)에 위치
    snake.push_back(make_pair(1, 1));
    board[1][1] = 1;

//    // test 출력
//    cout << "[준비]\n";
//    for (int i = 1; i < n + 1; i++) {
//        for (int j = 1; j < n + 1; j++) {
//            cout << board[i][j];
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//    cout << "[시작]\n";

    // 연산
    cnt = 0;
    direction = 0;
    while (true) {

        // 1초 카운트
        cnt++;

        // 한 칸 움직이기
        switch (direction) {
            // 오른쪽
            case 0 :
                snake.push_front(make_pair(snake.front().first, snake.front().second + 1));
                break;
                // 아래
            case 1 :
                snake.push_front(make_pair(snake.front().first + 1, snake.front().second));
                break;
                // 왼쪽
            case 2 :
                snake.push_front(make_pair(snake.front().first, snake.front().second - 1));
                break;
                // 위
            case 3 :
                snake.push_front(make_pair(snake.front().first - 1, snake.front().second));
                break;

        }

        // 뱀이 벽 또는 자기자신의 몸과 부딪히면 게임 종료
        if (snake.front().first < 1 || snake.front().first > n || snake.front().second < 1 ||
            snake.front().second > n || board[snake.front().first][snake.front().second] == 1)
            break;

        // 이동한 칸에 사과가 있다면
        if (board[snake.front().first][snake.front().second] == 2) {
            // 그 칸에 있던 사과는 없어지고 뱀이 그 자리로 이동, 꼬리는 움직이지 않음
            board[snake.front().first][snake.front().second]--;
        }
            // 이동한 칸에 사과가 없다면
        else if (board[snake.front().first][snake.front().second] == 0) {
            // 뱀의 머리가 그 자리로 이동
            board[snake.front().first][snake.front().second]++;
            // 뱀의 꼬리가 위치한 칸을 비워줌
            board[snake.back().first][snake.back().second]--;
            snake.pop_back();
        }

        // 방향 전환 여부 확인
        for (int i = 0; i < move.size(); i++) {
            if (move[i].first == cnt) {
                if (move[i].second == 'L') {
                    direction--;
                    if (direction < 0)
                        direction = 3;
                } else if (move[i].second == 'D') {
                    direction++;
                    if (direction > 3)
                        direction = 0;
                }

            }
        }

//        // test 출력
//        cout << "cnt: " << cnt << " / dir: " << direction << '\n';
//        for (int i = 1; i < n + 1; i++) {
//            for (int j = 1; j < n + 1; j++) {
//                cout << board[i][j];
//            }
//            cout << '\n';
//        }
//        cout << '\n';

    }

    // 출력
    cout << cnt;

}