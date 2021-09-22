//
// Created by 김채린 on 2021/09/17.
//

#include <cstdio>

long long solution(int N, int A[], int B, int C) {
    long long answer = N;   //각 시험장에 한 명의 총감독관 필요
    // 각 시험장
    for (int i = 0; i < N; i++) {
        int student = A[i];
        student -= B;
        if (student % C == 0)
            answer += (student / C);
        else
            answer += (student / C + 1);
    }
    return answer;
}

int main() {
    int N, B, C, i;
    int A[1000000] = {0};
    long long answer;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);
    scanf("%d", &B);
    scanf("%d", &C);
    answer = solution(N, A, B, C);
    printf("%lld\n", answer);
}