//
// Created by 김채린 on 2021/09/27.
//

#include <iostream>

using namespace std;

int main() {
    int r, b, l, w;
    cin >> r >> b;
    // 3 <= l,w <= 2499
    for (l = 3; l < 2500; l++) {
        for (w = 3; w < 2500; w++) {
            if (r == 2 * (l + w - 2) && b == (l - 2) * (w - 2)) {
                cout << max(l, w) << ' ' << min(l, w);
                return 0;
            }
        }
    }
}