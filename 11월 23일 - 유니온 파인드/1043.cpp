//
// Created by 김채린 on 2021/11/29.
//

#include <iostream>
#include <vector>

using namespace std;

// 사람들의 정보를 저장할 벡터 (1 : 진실을 말해야 하는 사람, 0 : 거짓을 말해도 되는 사람)
vector<int> people;

// 부모 노드를 저장할 벡터
vector<int> parent;

// 파티의 정보를 저장할 벡터
vector<vector<int>> party;

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

    // 입력
    // n : 사람의 수, m : 파티의 수, t : 진실을 아는 사람의 수
    int n, m, t, input;
    cin >> n >> m >> t;
    people.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    party.assign(m, vector<int>());
    // 진실을 아는 사람이 아무도 없으면 모든 파티에서 과장된 이야기를 할 수 있음
    if (t == 0) {
        cout << m;
        return 0;
    }
    // 처음부터 진실을 아는 사람의 목록
    vector<int> t_people(t, 0);
    for (int i = 0; i < t; i++) {
        cin >> t_people[i];
    }
    // 파티 정보 저장
    for (int i = 0; i < m; i++) {
        // 각 파티에 오는 사람 수
        int people_cnt;
        cin >> people_cnt;
        for (int j = 0; j < people_cnt; j++) {
            cin >> input;
            party[i].push_back(input);
        }
        // 각 파티에 오는 사람들끼리 Union 연산
        for (int j = 0; j < people_cnt - 1; j++) {
            unionInput(party[i][j], party[i][j + 1]);
        }
    }

    // 처음부터 진실을 아는 사람의 루트 노드를 찾아 people 벡터의 값을 1로 바꿔줌
    for (int i = 0; i < t; i++) {
        people[findParent(t_people[i])] = 1;
    }

    // 연산
    int answer = 0;
    // 각 파티
    for (int i = 0; i < m; i++) {
        bool can_lie = true;
        for (int j = 0; j < party[i].size(); j++) {
            if (people[findParent(party[i][j])] == 1) {
                can_lie = false;
                break;
            }
        }
        if (can_lie)
            answer++;
    }

    cout << answer;

}