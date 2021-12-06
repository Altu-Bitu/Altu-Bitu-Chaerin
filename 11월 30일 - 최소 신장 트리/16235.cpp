//
// Created by 김채린 on 2021/12/04.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 겨울에 S2D2가 각 칸에 추가할 양분의 정보
vector<vector<int>> a;
// 각 칸에 있는 양분의 정보
vector<vector<int>> land;
// 각 칸에 있는 나무의 정보
vector<vector<vector<int>>> trees;
// 죽은 나무가 각 칸에 남긴 양분 정보
vector<vector<int>> death;

vector<int> r = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> c = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n, m, k;    // n*n 크기의 땅, m개의 나무, k년이 지난 후 살아남은 나무의 수는?
    cin >> n >> m >> k;
    a.assign(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    land.assign(n + 1, vector<int>(n + 1, 5));
    trees.assign(n + 1, vector<vector<int>>(n + 1));

    while (m--) {
        int x, y, z;    // (x, y)에 나이가 z살인 나무 심기
        cin >> x >> y >> z;
        trees[x][y].push_back(z);
    }

    // k년의 과정을 거침
    while (k--) {

        // 매년 죽은 나무의 정보는 초기화됨
        death.assign(n+1, vector<int>(n+1, 0));

        // 봄 : 나무가 있는 칸의 경우 나이가 어린 나무부터 양분 먹기
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // 나무가 있는 칸의 경우
                if (!trees[i][j].empty()) {
                    // 나이가 어린 나무부터 양분 먹기 위해 나이순으로 나무 정렬
                    sort(trees[i][j].begin(), trees[i][j].end());
                    // 나이가 어린 나무부터 양분 먹기
                    for (int l = 0; l < trees[i][j].size(); l++) {
                        // 먹을 양분이 남아있으면
                        if (land[i][j] >= trees[i][j][l]) {
                            // 양분 먹기
                            land[i][j] -= trees[i][j][l];
                            // 나이 한 살 먹기
                            trees[i][j][l]++;
                        }
                            // 먹을 양분이 남아있지 않으면
                        else {
                            // 나무의 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가됨
                            death[i][j] += trees[i][j][l] / 2;
                            // 나무는 죽음
                            trees[i][j][l] = 0;
                        }
                    }
                }
            }
        }

        // 여름 : 봄에 죽은 나무가 양분으로 변함
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++){
                // 죽은 나무가 양분으로
                land[i][j] += death[i][j];
                // 죽은 나무 삭제
                trees[i][j].erase(remove(trees[i][j].begin(), trees[i][j].end(), 0), trees[i][j].end());
            }
        }

        // 가을 : 나무의 나이가 5의 배수인 칸의 경우 인접한 8개의 칸에 나이가 1인 나무 생기기
        // 겨울 : S2D2가 땅을 돌아다니면서 양분 추가
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                land[i][j] += a[i][j];
                if (!trees[i][j].empty()) {
                    for (int l = 0; l < trees[i][j].size(); l++) {
                        // 나무의 나이가 5의 배수인 경우
                        if (trees[i][j][l] % 5 == 0) {
                            // 인접한 8개의 칸에 나이가 1인 나무 생김 (땅을 벗어나는 칸 제외)
                            for (int ri = 0; ri < 8; ri++) {
                                int next_r = i + r[ri];
                                int next_c = j + c[ri];
                                if (next_r > 0 && next_r <= n && next_c > 0 && next_c <= n)
                                    trees[next_r][next_c].push_back(1);
                            }
                        }
                    }
                }
            }
        }

//        // 디버깅
//        cout << "[나무]\n";
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= n; j++) {
//                for (int l = 0; l < trees[i][j].size(); l++) {
//                    cout << trees[i][j][l];
//                }
//                cout << ' ';
//            }
//            cout << "\n";
//        }
//        cout << "\n";
//        cout << "[양분]\n";
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= n; j++) {
//                cout << land[i][j] << ' ';
//            }
//            cout << "\n";
//        }
//        cout << "\n";
    }

    // 출력
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cnt += trees[i][j].size();
        }
    }
    cout << cnt;

}