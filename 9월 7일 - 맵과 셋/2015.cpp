//
// Created by 김채린 on 2021/09/13.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    //입력
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int count = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += v[j];
            if (sum == k){
                count++;
            }
        }
    }

    //출력
    cout << count;

}
