//
// Created by 김채린 on 2021/09/23.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    long long result1, result2;
    cin >> a >> b;

    long long c = a * b;

    for (int i = sqrt(c); i > 0; i--) {
        if (i % a == 0 && (c / i) % a == 0) {
            result1 = i;
            result2 = c / i;
            cout << result1 << " " << result2;
            break;
        }
    }

}