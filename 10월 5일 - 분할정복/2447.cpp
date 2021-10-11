//
// Created by 김채린 on 2021/10/11.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> vec;

void star(int n, int row, int col) {
    if (n == 3) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1)
                    continue;
                vec[row + i][col + j] = "*";
            }
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1)
                continue;
            star(n / 3, row + i * n / 3, col + j * n / 3);
        }
    }

}

int main() {

    // 입력
    int n;
    cin >> n;

    // 벡터 초기화
    vec.assign(n, vector<string>(n, " "));

    // 별찍기
    star(n, 0, 0);

    // 출력
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            cout << vec[i][j];
        }
        cout << '\n';
    }

}