//
// Created by 김채린 on 2021/09/17.
//

#include <cstdio>
#include <string>

using namespace std;

bool solution(int input) {
    int original_input = input;
    int reversed_input = 0;
    while (input > 0) {
        reversed_input = reversed_input * 10 + input % 10;
        input /= 10;
    }
    return original_input == reversed_input;
}

int main() {
    int input;
    while (true) {
        scanf("%d", &input);
        if (input == 0)
            return 0;
        printf("%s\n", solution(input) ? "yes" : "no");
    }
    return 0;
}