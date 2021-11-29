//
// Created by 김채린 on 2021/11/22.
//

#include <iostream>
#include <vector>

using namespace std;

void makeTree(int currentNode, int parent, vector<vector<int>> &tree1, vector<vector<int>> &tree2) {
    for (int i = 0; i < tree1[currentNode].size(); i++) {
        if (tree1[currentNode][i] != parent) {
            // add Node to currentNode's child, set Node's parent to currentNode
            tree2[currentNode].push_back(tree1[currentNode][i]);
            makeTree(tree1[currentNode][i], currentNode, tree1, tree2);
        }
    }
}

void countSubtreeNodes(int currentNode, vector<vector<int>> &tree2, vector<int> &count) {
    count[currentNode] = 1;
    for (int i = 0; i < tree2[currentNode].size(); i++) {
        countSubtreeNodes(tree2[currentNode][i], tree2, count);
        count[currentNode] += count[tree2[currentNode][i]];
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // n : 트리의 정점의 수, r : 루트의 번호, q : 쿼리의 수
    int n, r, q;
    cin >> n >> r >> q;

    // 주어진 트리
    vector<vector<int>> tree1(n + 1, vector<int>(0));

    // 루트를 확정한 후 다시 그린 트리
    vector<vector<int>> tree2(n + 1, vector<int>(0));

    for (int i = 0; i < n - 1; i++) {
        // u와 v를 양 끝점으로 하는 간선이 트리에 속함
        int u, v;
        cin >> u >> v;
        tree1[u].push_back(v);
        tree1[v].push_back(u);
    }

    makeTree(r, -1, tree1, tree2);

    // 서브트리의 정점의 개수를 저장할 벡터
    vector<int> count(n + 1, 0);

    countSubtreeNodes(r, tree2, count);

    while (q--) {
        int u;
        cin >> u;
        cout << count[u] << "\n";
    }
}