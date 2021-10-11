//
// Created by 김채린 on 2021/10/11.
//

#include <iostream>
#include <cmath>

using namespace std;

int cnt = 0;

// 이중벡터를 4등분하는 함수
void divide(int size, int row, int col) {

    // 사각형의 크기가 1이면 conquer
    if (size == 1)
        cnt++;

    // 사각형의 크기가 2 이상이면
    else {
        // 작은 사각형의 크기
        int small_box = pow(size / 2, 2);

        // 4등분 중 왼쪽 위
        if (row < size / 2 && col < size / 2) {
            divide(size / 2, row, col);
        }
        // 4등분 중 오른쪽 위
        if (row < size / 2 && col >= size / 2) {
            cnt += small_box;
            divide(size / 2, row, col - (size / 2));
        }
        // 4등분 중 왼쪽 아래
        if (row >= size / 2 && col < size / 2) {
            cnt += small_box * 2;
            divide(size / 2, row - (size / 2), col);
        }
        // 4등분 중 오른쪽 아래
        if (row >= size / 2 && col >= size / 2) {
            cnt += small_box * 3;
            divide(size / 2, row - (size / 2), col - (size / 2));
        }
    }

}

int main() {

    // 입력
    int n, r, c;
    cin >> n >> r >> c;

    // 연산
    divide(pow(2, n), r, c);

    // 출력 (0부터 카운트 시작하므로 -1)
    cout << cnt - 1;

}