//
// Created by 김채린 on 2021/11/06.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 첫 번째 모양일 경우
int first(int n, int m, vector<vector<int>> vec) {
    int maximum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (m - 3); j++) {
            int sum = vec[i][j] + vec[i][j + 1] + vec[i][j + 2] + vec[i][j + 3];
            if (sum > maximum)
                maximum = sum;
        }
    }
    return maximum;
}

// 첫 번째 모양을 회전한 경우
int first_rotate(int n, int m, vector<vector<int>> vec) {
    int maximum = 0;
    for (int i = 0; i < (n - 3); i++) {
        for (int j = 0; j < m; j++) {
            int sum = vec[i][j] + vec[i + 1][j] + vec[i + 2][j] + vec[i + 3][j];
            if (sum > maximum)
                maximum = sum;
        }
    }
    return maximum;
}

// 두 번째 모양일 경우
int second(int n, int m, vector<vector<int>> vec) {
    int maximum = 0;
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < (m - 1); j++) {
            int sum = vec[i][j] + vec[i][j + 1] + vec[i + 1][j] + vec[i + 1][j + 1];
            if (sum > maximum)
                maximum = sum;
        }
    }
    return maximum;
}

// 세 번째 or 다섯 번째 모양일 경우 (세칸짜리가 세로로 배치)
int third_vertical(int n, int m, vector<vector<int>> vec) {
    int maximum = 0;
    for (int i = 0; i < (n - 2); i++) {
        for (int j = 0; j < m; j++) {
            int sum = vec[i][j] + vec[i + 1][j] + vec[i + 2][j];
            if (j == 0)
                sum = max({sum + vec[i][j + 1], sum + vec[i + 1][j + 1], sum + vec[i + 2][j + 1]});
            else if (j == m - 1)
                sum = max({sum + vec[i][j - 1], sum + vec[i + 1][j - 1], sum + vec[i + 2][j - 1]});
            else
                sum = max({sum + vec[i][j + 1], sum + vec[i + 1][j + 1], sum + vec[i + 2][j + 1], sum + vec[i][j - 1],
                           sum + vec[i + 1][j - 1], sum + vec[i + 2][j - 1]});
            if (sum > maximum)
                maximum = sum;
        }

    }
    return maximum;
}

// 세 번째 or 다섯 번째 모양일 경우 (세칸짜리가 가로로 배치)
int third_horizontal(int n, int m, vector<vector<int>> vec) {
    int maximum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (m - 2); j++) {
            int sum = vec[i][j] + vec[i][j + 1] + vec[i][j + 2];
            if (i == 0)
                sum = max({sum + vec[i + 1][j], sum + vec[i + 1][j + 1], sum + vec[i + 1][j + 2]});
            else if (i == n - 1)
                sum = max({sum + vec[i - 1][j], sum + vec[i - 1][j + 1], sum + vec[i - 1][j + 2]});
            else
                sum = max({sum + vec[i + 1][j], sum + vec[i + 1][j + 1], sum + vec[i + 1][j + 2], sum + vec[i - 1][j],
                           sum + vec[i - 1][j + 1], sum + vec[i - 1][j + 2]});
            if (sum > maximum)
                maximum = sum;
        }

    }
    return maximum;
}

// 네 번째 모양일 경우 (세로)
int forth_vertical(int n, int m, vector<vector<int>> vec) {
    int maximum = 0;
    for (int i = 0; i < (n - 2); i++) {
        for (int j = 0; j < (m - 1); j++) {
            int sum = vec[i][j] + vec[i][j + 1] + vec[i + 1][j] + vec[i + 1][j + 1] + vec[i + 2][j] + vec[i + 2][j + 1];
            sum = max(sum - (vec[i][j + 1] + vec[i + 2][j]), sum - (vec[i][j] + vec[i + 2][j + 1]));
            if (sum > maximum)
                maximum = sum;
        }
    }
    return maximum;
}

// 네 번째 모양일 경우 (가로)
int forth_horizontal(int n, int m, vector<vector<int>> vec) {
    int maximum = 0;
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < (m - 2); j++) {
            int sum = vec[i][j] + vec[i][j + 1] + vec[i][j + 2] + vec[i + 1][j] + vec[i + 1][j + 1] + vec[i + 1][j + 2];
            sum = max(sum - (vec[i + 1][j] + vec[i][j + 2]), sum - (vec[i][j] + vec[i + 1][j + 2]));
            if (sum > maximum)
                maximum = sum;
        }
    }
    return maximum;
}

int main() {

    // 입력
    int n, m;
    cin >> n >> m;
    vector<vector<int>> paper(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    // 연산 및 출력
    cout << max({first(n, m, paper), first_rotate(n, m, paper), second(n, m, paper), third_vertical(n, m, paper),
                 third_horizontal(n, m, paper), forth_vertical(n, m, paper), forth_horizontal(n, m, paper)});

}