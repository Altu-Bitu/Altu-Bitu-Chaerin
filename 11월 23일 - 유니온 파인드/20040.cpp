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

    // 입력
    // n : 점의 개수, m : 진행된 차례의 수
    int n, m;
    cin >> n >> m;
    parent.assign(n, -1);

    for (int i = 1; i <= m; i++) {
        int input1, input2;
        cin >> input1 >> input2;
        if (findParent(input1) == findParent(input2)) {
            cout << i;
            return 0;
        } else
            unionInput(input1, input2);

    }

    // m번의 차례를 모두 처리한 이후에도 종료되지 않았다면 0 출력
    cout << 0;
    return 0;

}