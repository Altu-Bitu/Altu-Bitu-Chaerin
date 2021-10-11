//
// Created by 김채린 on 2021/10/09.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 타자가 공을 쳐서 얻은 결과(1, 2, 3, 4)에 따라 선수들이 이동
int move(int result, vector<int> &ground) {
    // cnt : 홈에 도착한 선수의 수
    int cnt = 0;
    // 3번 주자부터 진출
    for (int i = 3; i > 0; i--) {
        // 주자가 홈으로 들어가는 경우
        if (i > (3 - result)) {
            cnt += ground[i];
            ground[i] = 0;
        } else {
            ground[i + result] = ground[i];
            ground[i] = 0;
        }
    }
    // 홈런인 경우 타자도 홈으로 들어감
    if (result == 4)
        cnt++;
    // 홈런이 아닌 경우 타자는 자기 자리를 찾아감
    else
        ground[result] = 1;
    return cnt;
}

int main() {

    // 이닝 수
    int n;
    cin >> n;

    // 각 선수가 각 이닝에서 얻는 결과를 저장할 이중벡터
    vector<vector<int>> vec(n, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> vec[i][j];
        }
    }

    // 가능한 하나의 타순을 저장할 벡터
    vector<int> one_case;

    // 가능한 각각의 타순들을 저장할 이중벡터
    vector<vector<int>> cases;

    // 디폴트 타순
    vector<int> players = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // players 순열
    do {

        // 각 행의 0번째 인덱스에는 0 저장
        one_case.assign(1, 0);

        // 1번 선수를 제외하고 2번부터 9번 선수까지 순열
        for (int i = 2; i <= 9; i++) {
            one_case.push_back(players[i]);

            // 4번 타자는 무조건 1번 선수가
            if (i == 4)
                one_case.push_back(players[1]);
        }

        // 가능한 모든 타순을 cases 벡터에 한 행씩 저장
        cases.push_back(one_case);

    } while (next_permutation(players.begin() + 2, players.end()));

    // 경기장의 상황(1루, 2루, 3루에 선수가 있는지 여부)을 저장할 벡터
    vector<int> ground;

    // 각 이닝에서 아웃당한 횟수
    int out_cnt;

    // 각 케이스에서 얻을 수 있는 점수들 중 최대 점수
    int max_score = 0;

    // 각 케이스
    for (int i = 0; i < cases.size(); i++) {

        // 이번 케이스 예상 점수
        int score = 0;

        // 타석에 설 타자의 인덱스
        int player = 1;

        // 각 이닝
        for (int j = 0; j < n; j++) {

            ground = {0, 0, 0, 0};
            out_cnt = 0;

            // 아웃이 세 번 나올 때까지
            while (true) {

                int result = vec[j][cases[i][player]];

                if (result == 0)
                    out_cnt++;
                else
                    score += move(vec[j][cases[i][player]], ground);

                // 다음 선수 차례
                player++;
                if (player > 9)
                    player = 1;

                // 아웃이 세 번 나오면 이닝 종료
                if (out_cnt == 3)
                    break;

            }

        }

        max_score = max(score, max_score);

    }

    cout << max_score;

    return 0;

}