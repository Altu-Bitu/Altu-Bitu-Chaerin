//
// Created by 김채린 on 2021/11/29.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

// Find 연산
int findParent(int node) {
    if (parent[node] < 0) // 값이 음수면 루트 정점
        return node;
    return parent[node] = findParent(parent[node]); // 그래프 압축하며 루트 정점 찾기
}

// Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) // 같은 집합에 있다면 유니온 할 수 없음
        return;
    if (parent[xp] < parent[yp]) { // 새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else { // 새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int main() {

    // n : 도시의 수, m : 여행 계획에 속한 도시들의 수
    int n, m, input;
    cin >> n >> m;
    parent.assign(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> input;
            if (input == 1) {
                unionInput(i, j);
            }
        }
    }

    // 여행 일정을 저장할 벡터
    vector<int> trip(m, 0);
    for (int i = 0; i < m; i++)
        cin >> trip[i];

    // 연산
    bool can_trip = true;
    for (int i = 0; i < m - 1; i++) {
        if (findParent(trip[i]) != findParent(trip[i + 1]))
            can_trip = false;
    }

    // 출력
    cout << ((can_trip) ? "YES" : "NO");

}