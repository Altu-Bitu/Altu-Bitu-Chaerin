//
// Created by 김채린 on 2021/11/22.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // n : 트리의 정점의 개수, a 정점과 b 정점이 연결되어 있음
    int n, a, b;
    cin >> n;

    // 각 노드에 연결된 정점의 수를 저장할 벡터
    vector<int> count(n + 1, 0);

    for (int i = 1; i <= n-1; i++) {
        cin >> a >> b;
        count[a]++;
        count[b]++;
    }

    // q : 질의의 개수
    int q, t, k;
    cin >> q;

    while (q--) {
        cin >> t >> k;
        // k번 정점이 단절점인가? = k번 정점에 연결된 정점이 2개 이상인가?
        if (t == 1) {
            if (count[k] >= 2) cout << "yes\n";
            else cout << "no\n";
        }
        // k번째 간선이 단절선인가? (모든 간선이 다 단절선)
        if (t == 2) cout << "yes\n";
    }

}