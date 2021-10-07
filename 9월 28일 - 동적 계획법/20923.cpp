//
// Created by 김채린 on 2021/10/03.
//

#include <iostream>
#include <deque>

using namespace std;

int cnt;
deque<int> do_cards, do_ground, su_cards, su_ground;

// 각 상황에 맞는 사람이 종을 치고, 종을 치는 사람이 그라운드에 있는 카드 더미를 가져가는 함수
void bell() {
    // 수연이가 종을 치는 상황
    if (!do_ground.empty() && !su_ground.empty() && do_ground.back() + su_ground.back() == 5) {
        while (!do_ground.empty()) {
            su_cards.push_front(do_ground.front());
            do_ground.pop_front();
        }
        while (!su_ground.empty()) {
            su_cards.push_front(su_ground.front());
            su_ground.pop_front();
        }
    }
    // 도도가 종을 치는 상황
    if ((!do_ground.empty() && do_ground.back() == 5) || (!su_ground.empty() && su_ground.back() == 5)) {
        while (!su_ground.empty()) {
            do_cards.push_front(su_ground.front());
            su_ground.pop_front();
        }
        while (!do_ground.empty()) {
            do_cards.push_front(do_ground.front());
            do_ground.pop_front();
        }
    }
}

int main() {

    // 변수
    int n, m, input1, input2;

    // 입력
    cin >> n >> m;
    while (n--) {
        cin >> input1 >> input2;
        do_cards.push_back(input1);
        su_cards.push_back(input2);
    }

    // 게임 진행
    cnt = 0;
    while (true) {
        // 도도가 자신이 가진 덱에서 가장 위에 위치한 카드를 그라운드에 숫자가 보이도록 내려놓음
        do_ground.push_back(do_cards.back());
        do_cards.pop_back();
        if (do_cards.empty()) break;

        // 종치기 및 카드 가져가기
        bell();
        cnt++;
        if (cnt == m) break;

        // 수연이가 자신이 가진 덱에서 가장 위에 위치한 카드를 그라운드에 숫자가 보이도록 내려놓음
        su_ground.push_back(su_cards.back());
        su_cards.pop_back();
        if (su_cards.empty()) break;

        // 종치기 및 카드 가져가기
        bell();
        cnt++;
        if (cnt == m) break;
    }

    // 결과 출력
    if (do_cards.size() > su_cards.size())
        cout << "do";
    else if (su_cards.size() > do_cards.size())
        cout << "su";
    else
        cout << "dosu";

}