//
// Created by 김채린 on 2021/10/13.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> videos;

// 블루레이의 크기가 size로 정해져 있을 때, 필요한 블루레이의 수를 반환하는 함수
int cntBlueray(int size) {
    int sum = 0;
    int cnt = 0;
    for (int i = videos.size() - 1; i >= 0; i--) {
        sum += videos[i];
        if (sum > size) {
            sum = 0;
            cnt++;
            i++;
        }
    }
    return cnt + 1;
}

// lower search (주의 : 블루레이의 크가가 점점 커질수록 필요한 블루레이의 수는 점점 작아짐!!)
int lowerSearch(int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = cntBlueray(mid);
        if (cnt > target)
            left = mid + 1;
        else if (cnt <= target) {
            right = mid - 1;
        }
    }
    return right + 1;
}

int main() {

    // 입력
    int n, m;
    cin >> n >> m;
    videos.assign(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> videos[i];
        sum += videos[i];
    }

    // 연산 & 출력
    cout << lowerSearch(*max_element(videos.begin(), videos.end()), sum, m);

    return 0;

}