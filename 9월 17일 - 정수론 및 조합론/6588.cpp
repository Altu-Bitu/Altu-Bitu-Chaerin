//
// Created by 김채린 on 2021/09/23.
//

#include <iostream>
#include <vector>
#include <cmath>

#define SIZE 1000000

using namespace std;

vector<bool> isPrime(vector<bool> v) {
    for (int i = 2; i <= sqrt(SIZE); i++) {
        if (!v[i])
            continue;
        for (int j = i * i; j <= SIZE; j += i)
            v[j] = false;
    }
    return v;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input;

    // 각 자연수가 소수인지 저장하는 벡터
    vector<bool> is_prime(SIZE + 1, true);
    is_prime = isPrime(is_prime);

    // input으로 0이 들어올 때 까지 반복
    while (1) {
        cin >> input;
        if (input == 0)
            break;
        bool goldbach = false;
        for (int i = 2; i <= input / 2; i++) {
            if (is_prime[i] && is_prime[input - i]) {
                goldbach = true;
                cout << input << " = " << i << " + " << input - i << '\n';
                break;
            }
        }
        if (!goldbach)
            cout << "Goldbach's conjecture is wrong.\n";
    }
}