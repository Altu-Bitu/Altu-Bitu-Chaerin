//
// Created by 김채린 on 2021/09/23.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {

    // 입력 속도 단출
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n, p, a, b, cnt;
    cin >> n >> p;

    // 현재 기타의 상태를 저장할 이중벡터
    vector<vector<int>> guitar_state(7, vector<int>(p, 0));

//    // 기타연주 및 상태 update, 손가락 움직임 count
//    while (n--) {
//        cin >> a >> b;
//        if (guitar_state[a] <= b) {
//            cnt++;
//            guitar_state[a] = b;
//        } else {
//            cnt += 2;
//            guitar_state[a] = b;
//        }
//    }

    cout << cnt;

}