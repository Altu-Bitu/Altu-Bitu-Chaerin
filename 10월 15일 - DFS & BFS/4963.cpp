//
// Created by 김채린 on 2021/11/07.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int w, h;
vector<vector<int>> map;

void bfs(int r, int c) {
    queue<pair<int, int>> q;

    q.push(make_pair(r, c));
    map[r][c] = 0;

    // 탐색
    while (!q.empty()) {

        pair<int, int> node = q.front();
        q.pop();

        // 가능한 자식 노드
        vector<pair<int, int>> next = {make_pair(node.first - 1, node.second - 1),
                                       make_pair(node.first - 1, node.second),
                                       make_pair(node.first - 1, node.second + 1),
                                       make_pair(node.first, node.second - 1),
                                       make_pair(node.first, node.second + 1),
                                       make_pair(node.first + 1, node.second - 1),
                                       make_pair(node.first + 1, node.second),
                                       make_pair(node.first + 1, node.second + 1)};

        for (int i = 0; i < next.size(); i++) {
            int next_r = next[i].first;
            int next_c = next[i].second;
            if (0 <= next_r && next_r < h && 0 <= next_c && next_c < w &&
                map[next_r][next_c] == 1) {
                map[next_r][next_c] = 0;
                q.push(next[i]);
            }
        }
    }

}

int main() {

    while (true) {

        // 입력
        cin >> w >> h;
        if (w == 0)
            break;
        map.assign(h, vector<int>(w, 0));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        // 연산
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == 1) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';

    }

}