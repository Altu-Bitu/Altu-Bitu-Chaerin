//
// Created by 김채린 on 2021/09/27.
//

#include <iostream>

using namespace std;

int tri(int n) {
    return n * (n + 1) / 2;
}

int main() {
    int t;
    cin >> t;

    // 각 테스트케이스
    while (t--){
        int input;
        cin >> input;
        bool triangle = false;
        // n이 45일 때 t(n)값은 처음으로 1000을 넘어감
        for (int i=1; i<45; i++){
            for (int j=1; j<45; j++){
                for (int k=1; k<45; k++){
                    if (input == tri(i)+tri(j)+tri(k)){
                        triangle = true;
                        goto outside;
                    }
                }
            }
        }
        outside:
        if(triangle) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}