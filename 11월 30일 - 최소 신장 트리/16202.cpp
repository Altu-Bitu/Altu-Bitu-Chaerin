//
// Created by 김채린 on 2021/12/04.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;
priority_queue<tp, vector<tp>, greater<>> pq;
priority_queue<tp, vector<tp>, greater<>> pq2;

// pq 복사
void copyPQ() {
    while (!pq2.empty()) {
        pq.push(pq2.top());
        pq2.pop();
    }
}

// Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node;
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

// Union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return false;
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else { //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return true;
}

// kruskal
int kruskal(int n) {
    int cnt = 0, sum = 0;
    int weight, x, y;
    while (!pq.empty()) {
        weight = get<0>(pq.top());
        x = get<1>(pq.top());
        y = get<2>(pq.top());
        pq.pop();
        if (unionInput(x, y)) { //유니온 했다면
            cnt++;
            sum += weight;
            if (cnt != 1)
                pq2.push({weight, x, y});
        } else
            pq2.push({weight, x, y});
    }
    if (cnt == n - 1)
        return sum;
    return 0;
}

int main() {

    // n : 정점의 개수, m : 간선의 개수, k : 턴의 수
    int n, m, k;

    // 입력
    cin >> n >> m >> k;

    parent.assign(n + 1, -1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        pq.push({i, x, y});
    }

    // 연산 & 출력
    k--;
    cout << kruskal(n) << ' ';
    while (k--) {
        parent.assign(n + 1, -1);
        copyPQ();
        cout << kruskal(n) << ' ';
    }

}