//
// Created by 김채린 on 2021/09/27.
//

#include <iostream>
#include <vector>

using namespace std;

// 2n개 칸
// 내구도가 0인 칸의 개수가 k개 이상이면 종료
// step번째 단계
// cnt : 내구도가 0인 칸의 개수
int n, k, step, cnt;

// up : 올리는 위치
// down : 내리는 위치
int up, down;

// 벨트가 한 칸 이동
void belt_next() {
    up--;
    if (up < 1) up = 2 * n;
    down--;
    if (down < 1) down = 2 * n;
}

// 로봇이 한 칸 이동
void robot_next(vector<int> belt, vector<int> robot) {
    int pointer = down - 1;
    while (pointer != up) {
        // 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있는 경우
        if (robot[pointer + 1] == 0 && robot[pointer] == 1 && belt[pointer + 1] > 0) {
            robot[pointer + 1] = 1;
            robot[pointer] = 0;
            belt[pointer + 1]--;
            if (belt[pointer + 1] == 0)
                cnt++;
        }
        pointer--;
        if (pointer == 0)
            pointer = 2 * n;
    }
}

int main() {

    // 입력
    cin >> n >> k;

    // 벨트의 현재 상태(내구도)를 저장할 벡터
    vector<int> belt(2 * n + 1, 0);

    // 로봇이 있는 곳을 저장할 벡터
    vector<int> robot(n + 1, 0);

    // 벨트 각 칸의 내구도 입력
    for (int i = 1; i <= 2 * n; i++)
        cin >> belt[i];

    // up : 올리는 위치
    // down : 내리는 위치
    up = 1;
    down = n;

    while (cnt < k) {
        // 몇 번째 단계인지
        step++;

        // Step1. 벨트가 한 칸 이동 (로봇도 자동으로 함께 이동)
        belt_next();

        // 로봇이 내려가는 위치에 도달하면 내려가기
        if (robot[down] == 1)
            robot[down] = 0;

        // Step2. 로봇이 한 칸 이동
        robot_next(belt, robot);

        // 로봇이 내려가는 위치에 도달하면 내려가기
        if (robot[down] == 1)
            robot[down] = 0;

        // Step3. 올리는 위치의 내구도가 0이 아니면 올리는 위치에 로봇 올리기
        if (belt[up] > 0) {
            robot[up] = 1;
            belt[up]--;
            if (belt[up] == 0)
                cnt++;
        }

    }

}