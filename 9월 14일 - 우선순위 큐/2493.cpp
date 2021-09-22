//
// Created by 김채린 on 2021/09/20.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n, tmp;
    cin >> n;
    vector<int> v;
    while (n--) {
        cin >> tmp;
        v.push_back(tmp);
    }

    // 연산
    bool received;
    vector<int> result;
    for (int i = 0; i < v.size(); i++) {
        received = false;
        for (int j = i - 1; j >= 0; j--) {
            if (v[j] >= v[i]) {
                result.push_back(j+1);
                received = true;
                break;
            }
        }
        if (!received){
            result.push_back(0);
        }

    }

    // 출력
    for (int i = 0; i < v.size(); i++)
        cout << result[i] << ' ';

}
