//
// Created by 김채린 on 2021/11/07.
//

// 19538은 올려주신 소스코드를 참고하여 모든 줄에 주석을 달아 제출합니다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 너비 우선 탐색 (BFS)
vector<int> bfs(vector<vector<int>> rumor, vector<int> first, int n) {

    // 너비 우선 탐색에 필요한 큐 q
    queue<int> q;
    // 각 사람의 주변인 중 몇 명이 루머를 믿는지 저장할 벡터 believer
    vector<int> believer(n + 1, 0);
    // 각 사람이 몇 분 후에 루머를 믿게 되는지 저장할 벡터 ans
    vector<int> ans(n + 1, -1);

    // 시작 정점 초기화 (최초유포자)
    for (int i = 0; i < first.size(); i++) {
        // 최초유포자는 처음(0분)부터 루머를 믿기 시작함
        ans[first[i]] = 0;
        // 최초유포자 번호를 q에 push
        q.push(first[i]);
    }

    // 탐색
    while (!q.empty()) {
        // 현재 고려 대상인 사람의 번호
        int node = q.front();
        // 현재 고려 대상인 사람이 루머를 믿게 되는 시간
        int time = ans[node];
        // 현재 고려 대상인 사람의 번호를 q에서 pop
        q.pop();

        // 현재 고려 대상인 사람의 주변인들(총 rumor[node].size 명)이 루머를 믿게 됨
        for (int i = 0; i < rumor[node].size(); i++) {
            // 현재 고려 대상인 사람의 주변인 중 한명
            int next = rumor[node][i];
            // next 번호를 가진 사람 주변에 루머를 믿게 되는 사람 수 증가
            believer[next]++;
            // next 번호를 가진 사람이 이미 루머를 믿고 있으면
            if (ans[next] != -1)
                // 다음 주변인으로 넘어감
                continue;
            // next 번호를 가진 사람의 주변인들 중 절반 이상이 루머를 믿으면
            if ((rumor[next].size() + 1) / 2 <= believer[next]) {
                // next 번호를 가진 사람도 루머를 믿게 됨
                ans[next] = time + 1;
                // next 번호를 q에 push
                q.push(next);
            }
        }
    }
    return ans;
}

/**
 * 주변인들이 얼마나 믿는지를 배열을 통해 관리해야 함
 * 방문 체크를 탐색할 때 바로 하는 게 아니라, 루머를 믿게 될 경우 하는 게 중요 (루머를 몇 분 후에 믿는지를 저장하는 배열로 관리)
 */

int main() {

    // 입력
    // n : 사람의 수
    int n;
    cin >> n;
    // 사람들간의 관계(그래프)를 저장할 이중벡터(인접리스트) rumor
    vector<vector<int>> rumor(n + 1, vector<int>());
    // 이중벡터 rumor 채우기
    for (int i = 1; i <= n; i++) {
        // 0이 입력되기 전까지는 i번째 사람의 주변인 번호를 계속해서 입력받음
        while (true) {
            // 입력받은 i번쨰 사람의 주변인 번호
            int input;
            cin >> input;
            // 입력값이 0이면
            if (input == 0)
                // i번째 사람의 주변인 번호 입력받기 중단
                break;
            // 입력값이 0이 아니면
            rumor[i].push_back(input);
        }
    }
    // m : 최초 유포자의 수
    int m;
    cin >> m;
    // 최초 유포자 정보를 저장할 벡터 first
    vector<int> first(m, 0);
    // 벡터 first 채우기
    for (int i = 0; i < m; i++)
        cin >> first[i];

    // 연산
    vector<int> result = bfs(rumor, first, n);

    // 출력
    for (int i = 1; i <= n; i++)
        cout << result[i] << ' ';

}