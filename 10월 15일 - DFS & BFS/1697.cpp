//
// Created by 김채린 on 2021/11/07.
//

#include <iostream>
#include <queue>

using namespace std;

const int SIZE = 100000;

int bfs(int v, int k) {
    queue<int> q;
    vector<int> visited(SIZE + 1, 0);    // 방문 체크

    // 시작 노드
    q.push(v);
    visited[v] = 1;

    // 탐색
    while (!q.empty()) {
        int node = q.front();

        // 동생 발견!
        if (node == k)
            return visited[node] - 1;

        q.pop();
        vector<int> next = {node - 1, node + 1, node * 2};
        for (int i = 0; i < next.size(); i++) {
            // !!! 범위를 먼저 체크하지 않으면 ArrayIndexOutOfBounds 발생 가능..
            // !!! 같은 조건문 안에서도 순서가 중요하다... 기억..
            // 참고 : https://www.acmicpc.net/board/view/72356
            if (0 <= next[i] && next[i] <= SIZE && !visited[next[i]]) {
                visited[next[i]] = visited[node] + 1;
                q.push(next[i]);
            }
        }

    }

}


int main() {

    int n, k;
    cin >> n >> k;
    cout << bfs(n, k);

}