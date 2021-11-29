//
// Created by 김채린 on 2021/11/29.
//

#include <iostream>
#include <vector>

#define MAX 500*500*256*2

using namespace std;

int work(int n, int m, int b, int target_height, vector<vector<int>> &land) {
    int time = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣기
            if (land[i][j] > target_height) {
                int difference = land[i][j] - target_height;
                time += 2 * difference;
                b += difference;
            }
            // 인벤토리에서 블록 하나를 꺼내어 좌표 (i, j)의 가장 위에 있는 블록 위에 놓기
            if (land[i][j] < target_height) {
                int difference = target_height - land[i][j];
                time += difference;
                b -= difference;
            }
        }
    }
    // !!! 반복문 안에서 b<0를 판단하면 안 됨 !!!
    // 참고 : https://www.acmicpc.net/board/view/56133
    if (b < 0)
        return MAX;
    return time;
}

int main() {

    // 입력
    // n : 집터의 세로 길이, m : 집터의 가로 길이, b : 작업을 시작할 때 인벤토리에 있는 블록 수
    int n, m, b;
    // min_height : 초기 집터에서 가장 낮은 땅의 높이
    int min_height = 256;
    // max_height : 초기 집터에서 가장 높은 땅의 높이
    int max_height = 0;
    cin >> n >> m >> b;
    vector<vector<int>> land(n, vector(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> land[i][j];
            min_height = min(min_height, land[i][j]);
            max_height = max(max_height, land[i][j]);
        }
    }

    // 연산
    vector<int> time(257);
    int answer = MAX;
    for (int i = min_height; i <= max_height; i++) {
        time[i] = work(n, m, b, i, land);
        answer = min(answer, time[i]);
    }

//    // 디버깅
//    for (int i = max_height; i >= min_height; i--) {
//        cout << i << "높이로 만들기 : " << time[i] << "시간 소요\n";
//    }

    // 출력
    for (int i = max_height; i >= min_height; i--) {
        if (time[i] == answer) {
            cout << time[i] << ' ' << i;
            break;
        }
    }

}