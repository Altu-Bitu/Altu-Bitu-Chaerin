//
// Created by 김채린 on 2021/10/10.
//

#include <iostream>
#include <string>

using namespace std;

// conquer : 가장 가운데 값을 기준으로 양쪽 대칭되는 곳의 값이 서로 다른지 판단
bool conquer(string str) {

    // 문자열 길이
    int size = str.size();

    // 문자열 길이가 1이면
    if (size == 1)
        // true 반환
        return true;

        // 문자열 길이가 1이 아니면
    else {
        // 문자열의 가운데를 가리키는 인덱스
        int mid = size / 2;
        // 문자열의 왼쪽 부분을 차례로 확인할 인덱스
        int left = mid - 1;
        // 문자열의 오른쪽 부분을 차례로 확인할 인덱스
        int right = mid + 1;

        while (left >= 0 && right < str.size()) {
            // 가장 가운데 값을 기준으로 양쪽 대칭되는 곳의 값이 서로 같으면
            if (str[left] == str[right]) {
                // false 반환
                return false;
            }
                // 가장 가운데 값을 기준으로 양쪽 대칭되는 곳의 값이 서로 다르면
            else {
                // 인덱스 이동
                left--;
                right++;
            }
        }

        // 양쪽부분에서 동일한 과정을 반복
        // !!! 이미 가운데 값을 기준으로 대칭되는 곳이 서로 다른 값을 가지므로 둘 중 한 쪽만 검사해도 됨!
        // return (conquer(str.substr(0, mid)) && conquer(str.substr(mid + 1, str.size())));
        return (conquer(str.substr(0, mid)));
    }
}

int main() {

    // 테스트 케이스의 개수
    int t;
    cin >> t;

    // 각 테스트 케이스
    while (t--) {

        // 원룡이가 접었다 핀 종이의 정보
        string input;
        cin >> input;

        // 동호의 방법대로 다시 접을 수 있으려면
        // 가장 가운데 값을 기준으로 양쪽 대칭되는 곳의 값이 서로 달라야 함 (양쪽부분에서 반복)

        // 결과 출력
        if (conquer(input))
            cout << "YES\n";
        else
            cout << "NO\n";

    }

}