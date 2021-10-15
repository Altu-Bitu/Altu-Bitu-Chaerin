//
// Created by 김채린 on 2021/10/13.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<string, int>> titles;

// lower search
int lowerBound(int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (titles[mid].second >= target)
            right = mid - 1;
        if (titles[mid].second < target)
            left = mid + 1;
    }
    return right + 1;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력
    int n, m, input;
    string str;
    cin >> n >> m;
    titles.assign(n, pair<string, int>("", 0));
    for (int i = 0; i < n; i++)
        cin >> titles[i].first >> titles[i].second;
    while (m--){
        cin >> input;
        cout << titles[lowerBound(0, n - 1, input)].first << "\n";
    }

    return 0;

}