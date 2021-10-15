//
// Created by 김채린 on 2021/10/13.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// a번째 친구가 건너뛰어야 하는 최대 거리를 반환하는 함수
int max_jump(vector<int> stones, int a) {
    int max_cnt = 0;
    int cnt = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] < a) {
            cnt++;
            max_cnt = max(max_cnt, cnt);
        } else
            cnt = 0;
    }
    return max_cnt + 1;
}

// upper search
int upperSearch(vector<int> stones, int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        int jump = max_jump(stones, mid);
        if (jump > target)
            right = mid - 1;
        else if (jump <= target) {
            left = mid + 1;
        }
    }
    return right;
}

int solution(vector<int> stones, int k) {
    return upperSearch(stones, 1, *max_element(stones.begin(), stones.end()), k);
}

int main() {

    // 입력
    vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    int k = 3;

    // 연산 & 출력
    cout << solution(stones, k);

    return 0;

}