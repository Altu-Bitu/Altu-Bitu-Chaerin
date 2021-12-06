//
// Created by 김채린 on 2021/12/05.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;
priority_queue<tp, vector<tp>, greater<>> pq;

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
long long kruskal(int n) {
    int cnt = 0;
    long long sum = 0;
    int x, y;
    long long weight;
    while (!pq.empty()) {
        weight = get<0>(pq.top());
        x = get<1>(pq.top());
        y = get<2>(pq.top());
        pq.pop();
        if (unionInput(x, y)) { //유니온 했다면
            cnt++;
            sum += weight;
        }
    }
    if (cnt == n - 1)
        return sum;
    return -1;
}

int main() {

    // n : 건물의 개수, m : 도로의 개수, sum : 모든 도로를 다 설치할 떄 드는 비용
    int n, m;
    long long sum = 0;

    // 입력
    cin >> n >> m;
    parent.assign(n + 1, -1);
    while (m--) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        sum += c;
        pq.push({c, a, b});
    }

    // 연산 & 출력
    long long answer = kruskal(n);
    if (answer == -1)
        cout << -1;
    else
        cout << sum - answer;

}