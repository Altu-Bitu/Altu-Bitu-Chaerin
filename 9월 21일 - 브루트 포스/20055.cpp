//
// Created by 김채린 on 2021/09/27.
//

#include <iostream>
#include <vector>

using namespace std;

// 변수
// n : 위에 n개, 아래 n개, 총 2n개 칸
// k : 내구도가 0인 칸의 개수가 k개 이상이면 종료
// step : 현재 진행중인 단계가 몇 번째 단계인지
// cnt : 내구도가 0인 칸의 개수
// up : 올리는 위치
// down : 내리는 위치
int n, k, step, cnt, up, down;

// 벨트의 현재 상태(내구도)를 저장할 벡터
vector<int> belt;

// 벨트 윗줄의 현재 상태(로봇이 있는지 여부)를 저장할 벡터
vector<int> robot;

// 벨트가 한 칸 이동
int belt_next(int index) {
    // 인덱스가 하나 줄어듦
    index--;
    // 인덱스가 1이었으면 그 다음 단계에는 인덱스가 2*n이 됨
    if (index < 1) index = 2 * n;
    return index;
}

// 로봇이 한 칸 이동
void robot_next() {
    // 내리는 칸에 로봇이 있는지 확인 후 이미 로봇을 내렸으므로, 내리는 칸은 비어있음
    // 따라서 내리는 칸 직전의 칸부터 하나씩 역으로 확인
    int pointer = down - 1;
    // 내리는 칸의 인덱스가 1인 경우
    // 그 직전 칸의 인덱스는 0이 아니라 2*n임
    if (pointer == 0) pointer = 2 * n;
    // 벨트가 한 칸 이동 한 후 아직 새로운 로봇을 올리지 않았으므로, 올리는 위치는 비어있음
    // 따라서 올리는 위치 직후의 칸까지 확인
    while (pointer != up) {
        // next : 로봇이 이동할 칸(지금 확인하는 칸의 다음 칸)의 인덱스
        int next = pointer + 1;
        // 지금 확인하는 칸의 인덱스가 2*n인 경우
        // 그 다음 칸의 인덱스는 2*n+1이 아니라 1임
        if (next > 2 * n) next = 1;
        // 지금 확인하는 칸에 로봇이 있으며, 로봇이 이동할 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상인 경우
        if (robot[pointer] == 1 && robot[next] == 0 && belt[next] > 0) {
            // 지금 확인하는 칸에서 로봇을 들어서
            robot[pointer] = 0;
            // 로봇이 이동할 칸으로 옮김
            robot[next] = 1;
            // 로봇이 이동한 칸의 내구도가 1 감소
            belt[next]--;
            // 로봇이 이동한 칸의 내구도가 0이 되었다면 cnt 증가
            if (belt[next] == 0)
                cnt++;
        }
        // 바로 전의 칸을 확인
        pointer--;
        // 지금 확인하는 칸의 인덱스가 1인 경우
        // 그 이전 칸의 인덱스는 0이 아니라 2*n임
        if (pointer == 0)
            pointer = 2 * n;
    }
}

int main() {

    // 입력
    cin >> n >> k;

    // 변수 초기화
    step = 0;
    cnt = 0;
    up = 1;
    down = n;

    // 벡터 초기화
    belt.assign(2 * n + 1, 0);
    robot.assign(2 * n + 1, 0);

    // 벨트 각 칸의 내구도 입력
    for (int i = 1; i <= 2 * n; i++)
        cin >> belt[i];

    // Step4에서 내구도가 0인 칸의 개수가 K개 이상인지 판단해서 과정을 종료하기 전까지 무한 반복
    while (true) {
        // 현재 몇 번째 단계를 진행중인지
        step++;

        // Step1. 벨트가 한 칸 이동 (로봇도 자동으로 함께 이동)
        up = belt_next(up);
        down = belt_next(down);

        // 로봇이 내리는 위치에 도달하면 그 즉시 내리기
        if (robot[down] == 1)
            robot[down] = 0;

        // Step2. 로봇이 한 칸 이동
        robot_next();

        // 로봇이 내리는 위치에 도달하면 그 즉시 내리기
        if (robot[down] == 1)
            robot[down] = 0;

        // Step3. 올리는 위치의 내구도가 0이 아니면 올리는 위치에 로봇 올리기
        if (belt[up] > 0) {
            robot[up] = 1;
            // 로봇이 올라간 칸의 내구도가 1 감소
            belt[up]--;
            // 로봇이 올라간 칸의 내구도가 0이 되었다면 cnt 증가
            if (belt[up] == 0)
                cnt++;
        }

        // Step4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정 종료
        if (cnt >= k)
            break;
    }

    // 몇 번째 단계가 진행 중일때 종료되었는지 출력
    cout << step;

}