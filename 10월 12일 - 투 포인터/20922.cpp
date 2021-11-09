//
// Created by 김채린 on 2021/11/06.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // 입력
    int n, k;
    cin >> n >> k;
    vector<int> numbers(n, 0);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    // 각 수가 몇 번 등장했는지 표시할 벡터
    vector<int> count(100001, 0);

    // 시작, 끝 포인터
    int start = 0;
    int end = 0;

    // 현재까지 최장 연속 부분 수열의 길이
    int max_length = 0;

    // 항상 start <= end < n 이어야 함
    while (start <= end && end < n) {
        // 만약 end 포인터가 가리키는 수를 count 해도 k보다 작거나 같다면
        if (count[numbers[end]] + 1 <= k) {
            // 최장 연속 부분 수열 갱신 여부 판단
            max_length = max(end - start + 1, max_length);
            // end 포인터가 가리키는 수를 count 하고 end 포인터가 다음 수를 가리키도록
            count[numbers[end++]]++;
        }
        // 만약 end 포인터가 가리키는 수를 count 했을 때 k보다 커진다면
        else if (count[numbers[end]] + 1 > k) {
            // start 포인터가 가리키는 수를 count에서 빼고 start 포인터가 다음 수를 가리키도록
            count[numbers[start++]]--;
        }
    }

    cout << max_length;

}