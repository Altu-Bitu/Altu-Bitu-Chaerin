//
// Created by 김채린 on 2021/11/21.
//

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

// 현재 위치에서 현재 방향을 기준으로 왼쪽 방향의 칸, 회전했을 때 방향
pair<ci, int> checkLeft(pair<ci, int> robot) {
    if (robot.second == 0)
        return {{robot.first.first, robot.first.second - 1}, 3};
    if (robot.second == 1)
        return {{robot.first.first - 1, robot.first.second}, 0};
    if (robot.second == 2)
        return {{robot.first.first, robot.first.second + 1}, 1};
    else
        return {{robot.first.first + 1, robot.first.second}, 2};
}

// 현재 위치에서 현재 방향을 기준으로 뒤쪽 방향의 칸, 방향은 유지
pair<ci, int> checkBack(pair<ci, int> robot) {
    if (robot.second == 0)
        return {{robot.first.first + 1, robot.first.second}, 0};
    if (robot.second == 1)
        return {{robot.first.first, robot.first.second - 1}, 1};
    if (robot.second == 2)
        return {{robot.first.first - 1, robot.first.second}, 2};
    else
        return {{robot.first.first, robot.first.second + 1}, 3};
}

// 디버깅용 방 상태 출력
void printRoom(int n, int m, vector<vector<int>> &room) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << room[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

int cntCleanRobot(int r, int c, int d, vector<vector<int>> &room) {

    // 현재 로봇의 위치, 방향
    pair<ci, int> robot = {{r, c}, d};
    room[r][c] = 2;

    // 로봇청소기가 청소하는 칸의 수
    int clean_cnt = 1;

    while (true) {

        if (room[robot.first.first][robot.first.second] == 0) {
            room[robot.first.first][robot.first.second] = 2;
            clean_cnt++;
        }

        // cout << "CLEANCOUNT : " << clean_cnt << '\n';
        // printRoom(n, m, room);

        // 로봇청소기가 연속해서 회전한 수
        int rotate_cnt = 0;

        while (true) {
            int left_r = checkLeft(robot).first.first;
            int left_c = checkLeft(robot).first.second;
            int new_d = checkLeft(robot).second;
            if (room[left_r][left_c] == 0) {
                robot = {{left_r, left_c}, new_d};
                break;
            } else {
                robot = {{robot.first.first, robot.first.second}, new_d};
                rotate_cnt++;
                // cout << "rotate count : " << rotate_cnt << "\n";
            }
            if (rotate_cnt == 4) {
                int back_r = checkBack(robot).first.first;
                int back_c = checkBack(robot).first.second;
                if (room[back_r][back_c] != 1) {
                    robot = {{back_r, back_c}, new_d};
                    break;
                }
                else {
                    // cout << "종료 조건 : " << robot.first.first << " " << robot.first.second << " " << robot.second << "\n";
                    return clean_cnt;
                }
            }
        }

    }

}

int main() {

    // n : 세로 크기, m : 가로 크기, (r, c) : 로봇청소기가 있는 좌표
    // d : 로봇청소기가 바라보는 방향 (0 : 북쪽, 1 : 동쪽, 2 : 남쪽, 3 : 서쪽)
    int n, m, r, c, d;
    cin >> n >> m >> r >> c >> d;

    // 방의 상태를 저장할 이중벡터 (0 : 청소 X, 1 : 벽, 2 : 청소 O)
    vector<vector<int>> room(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }

    cout << cntCleanRobot(r, c, d, room);

}