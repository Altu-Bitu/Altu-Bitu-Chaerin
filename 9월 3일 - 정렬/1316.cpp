//
// Created by 김채린 on 2021/09/09.
//

#include <iostream>
#include <vector>

using namespace std;

//단어들의 배열
vector<string> arr;

int main() {
    int n;

    //입력
    cin >> n;
    arr.assign(n, {});
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //연산
    int result = 0;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < arr[i].length() - 1; j++) {
            // 연속된 값이 나타나지 않을 때, 알파벳이 달라질 때 : 앞에 중복된 알파벳이 있는지 확인
            if (arr[i][j] != arr[i][j+1]){
                for (int k = 0; k < j+1; k++){
                    if (arr[i][j+1] == arr[i][k])
                        flag = false;
                }
            }
        }
        if (flag)
            result++;
    }

    //출력
    cout << result << '\n';
}
