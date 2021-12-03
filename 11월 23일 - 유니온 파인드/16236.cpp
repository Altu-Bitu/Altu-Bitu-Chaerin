//
// Created by 김채린 on 2021/11/30.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 가능한 이동거리의 최댓값(20*20) + 1
const int INF = 401;
// 좌표정보를 저장할 pair
typedef pair<int, int> ci;

// 다음에 먹을 물고기까지의 거리와 다음에 먹을 물고기의 위치를 반환하는 함수(BFS)
pair<int, ci> nextPos(int n, int shark_size, ci &shark, vector<vector<int>> &board) {
    // 상, 하, 좌, 우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    // 최소거리를 저장할 변수 초기화
    int min_dist = INF;
    // 아기 상어가 갈 수 있는 곳
    queue<ci> q;
    // 해당 위치까지 가는 데 이동한 거리를 저장할 이중벡터
    vector<vector<int>> visited(n, vector<int>(n, 0));
    // 아기 상어가 먹을 수 있는 물고기들의 위치를 저장할 벡터
    vector<ci> list;
    // 현재 아기 상어 위치 저장
    visited[shark.first][shark.second] = 1;
    // 현재 아기 상어 위치를 큐에 push
    q.push(shark);
    // q가 빌 때까지
    while (!q.empty()) {
        // 현재 탐색하려는 위치의 행
        int row = q.front().first;
        // 현재 탐색하려는 위치의 열
        int col = q.front().second;
        // 현재 탐색하려는 위치까리의 거리
        int dist = visited[row][col];
        q.pop();
        // 최단거리 이상은 탐색할 필요 없음
        if (dist >= min_dist)
            continue;
        // 상, 하, 좌, 우
        for (int i = 0; i < 4; i++) {
            // 이동하려는 위치의 행
            int nr = row + dr[i];
            // 이동하려는 위치의 열
            int nc = col + dc[i];
            // 이동하려는 위치가 공간을 벗어나거나, 방문한 적이 있거나, 상어보다 큰 물고기가 있으면 이동 불가
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] || board[nr][nc] > shark_size)
                continue;
            // 위의 조건에 해당하지 않으면(이동할 수 있는 곳이면) 해당 장소까지 가는 데 이동한 거리 저장
            visited[nr][nc] = visited[row][col] + 1;
            // 먹을 수 있는 물고기를 발견하면
            if (board[nr][nc] && board[nr][nc] < shark_size) {
                // 먹을 수 있는 물고기들의 위치를 저장하는 벡터에 추가
                list.emplace_back(nr, nc);
                // 최단거리 갱신
                min_dist = visited[nr][nc];
                continue;
            }
            q.push({nr, nc});
        }
    }
    // 아기 상어가 더이상 갈 수 있는 곳이 없으면
    if (list.empty())
        // 지금까지의 최단 거리와 (-1, -1) 반환
        return {min_dist, {-1, -1}};
    // 정렬 (먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기 먹기)
    sort(list.begin(), list.end(), [](const ci &p1, const ci &p2) {
        // 거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기 먹기
        if (p1.first != p2.first)
            return p1.first < p2.first;
        // 가장 위에 있는 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기 먹기
        return p1.second < p2.second;
    });
    // 다음에 먹을 물고기까지의 거리와 다음에 먹을 물고기의 위치 반환
    return {min_dist - 1, list[0]};
}

// 시뮬레이션 함수
int simulation(int n, pair<int, int> &shark, vector<vector<int>> &board) {
    // ans : 아기 상어가 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는 시간
    // size : 아기 상어의 크기 (처음 크기 : 2)
    // cnt : 먹은 물고기의 수
    int ans = 0, size = 2, cnt = 0;
    // 무한루프 (더 이상 먹을 수 있는 물고기가 없을 때 까지)
    while (true) {
        // 다음에 먹을 물고기까지의 거리와 다음에 먹을 물고기의 위치를 result에 저장
        pair<int, ci> result = nextPos(n, size, shark, board);
        // 더이상 먹을 수 있는 물고기가 없으면
        if (result.first == INF)
            // 무한루프 탈출
            break;
        // 다음에 먹을 물고기까지의 거리를 ans에 더해줌 (이동한 거리만큼 시간이 소요되므로)
        ans += result.first;
        // 물고기 잡아먹음
        cnt++;
        // 자신의 크기와 같은 수의 물고기를 먹을 때마다
        if (cnt == size) {
            // cnt값을 초기화하고
            cnt = 0;
            // 아기 상어의 크기 1 증가
            size++;
        }
        // 잡아먹은 물고기가 있던 자리(상어가 이동할 자리)
        ci pos = result.second;
        // 기존에 상어가 있던 자리는 0으로 바꿔줌
        board[shark.first][shark.second] = 0;
        // 잡아먹은 물고기가 있던 자리로 상어 이동
        shark = pos;
    }
    // 아기 상어의 총 이동거리 (= 아기 상어가 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는 시간) 반환
    return ans;
}

/**
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */

int main() {
    // 공간의 크기
    int n;
    // 상어의 위치
    pair<int, int> shark_pos;
    // 공간의 크기 입력받기
    cin >> n;
    // 공간의 상태를 저장할 벡터
    vector<vector<int>> board(n, vector<int>(n));
    // 공간의 상태 입력받기(0 : 빈 칸, 1~6 : 칸에 있는 물고기의 크기, 9 : 아기 상어의 위치)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            // 입력값이 9이면
            if (board[i][j] == 9)
                // 상어의 위치 초기화
                shark_pos = make_pair(i, j);
        }
    }
    //연산 & 출력
    cout << simulation(n, shark_pos, board);
}