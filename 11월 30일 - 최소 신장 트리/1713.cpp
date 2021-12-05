//
// Created by 김채린 on 2021/12/03.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 사진틀에 걸린 사진들을 저장할 벡터
vector<int> pictures;

// 각 학생별로 추천받은 횟수를 저장할 벡터
vector<int> students(101, 0);

// 사진틀에 걸린 사진의 개수를 저장할 변수
int picture_cnt = 0;

// 사진틀에 걸린 사진들 중 추천 수가 가장 적은 사진의 추천 수를 구하는 함수
int min_recommend() {
    int answer = 1001;
    for (int i = 1; i <= 100; i++) {
        if (students[i])
            answer = min(answer, students[i]);
    }
    return answer;
}

void put_picture(int n, int input) {

    // 현재 사진이 게시된 학생이 추천을 받은 경우
    if (students[input] != 0) {
        // 해당 학생의 추천받은 횟수만 증가
        students[input]++;
    }
    // 새로운 학생이 추천을 받은 경우
    else {
        // 사진 틀에 빈 자리가 있을 경우
        if (picture_cnt < n) {
            // 추천받은 학생의 사진을 사진틀에 게시
            students[input]++;
            pictures.push_back(input);
            picture_cnt++;
        }
        // 사진 틀에 빈 자리가 없을 경우
        else {
            // 현재까지 추천받은 횟수가 가장 적은 학생들의 사진 중 게시된지 가장 오래된 사진을 삭제
            for (int i = 0; i < pictures.size(); i++) {
                if (students[pictures[i]] == min_recommend()) {
                    // 사진틀에 게시된 사진이 삭제되는 경우 해당 학생이 추천받은 횟수는 0으로 바뀜
                    students[pictures[i]] = 0;
                    pictures.erase(find(pictures.begin(), pictures.end(), pictures[i]));
                    break;
                }
            }
            // 새롭게 추천받은 학생의 사진을 사진틀에 게시
            students[input]++;
            pictures.push_back(input);
        }
    }
}

int main() {

    // n : 사진틀의 개수, m : 전체 학생의 총 추천 횟수, input : 추천받은 학생
    int n, m, input;
    cin >> n >> m;

    // 연산
    while (m--) {
        cin >> input;
        put_picture(n, input);
    }

    // 출력
    for (int i = 1; i <= 100; i++) {
        if (students[i])
            cout << i << ' ';
    }

}