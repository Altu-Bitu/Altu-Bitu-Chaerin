//
// Created by 김채린 on 2021/09/13.
//

#include <iostream>

using namespace std;

int main() {
    //입력
    //다이어트 전 체중, 다이어트 전 일일 에너지 섭취량 == 일일 기초 대사량, 기초 대사량 변화 역치
    int w_before, l_before, t;
    //다이어트 기간, 다이어트 기간 일일 에너지 섭취량, 다이어트 기간 일일 활동 대사량
    int d, l, A;
    cin >> w_before >> l_before >> t >> d >> l >> A;

    //일일 기초 대사량의 변화를 고려하지 않았을 때
    int w_after = w_before;
    bool danger = false;
    for (int i = 0; i < d; i++) {
        int w_increase = l - (l_before + A);
        w_after += w_increase;
        if (w_after <= 0 || l_before <= 0) {
            danger = true;
        }
    }

    //출력
    //다이어트 후 예상 체중, 일일 기초 대사량
    if (danger)
        cout << "Danger Diet" << '\n';
    else
        cout << w_after << ' ' << l_before << '\n';

    //일일 기초 대사량의 변화를 고려했을 때
    w_after = w_before;
    int l_after = l_before;
    danger = false;
    bool yoyo = false;
    for (int i = 0; i < d; i++) {
        int w_increase = l - (l_after + A);
        w_after += w_increase;
        if (abs(w_increase) > t)
            l_after += w_increase / 2;
        if (w_after <= 0 || l_after <= 0) {
            danger = true;
        }
    }

    int w_after_end = w_after + (l_before - l_after);
    if (w_after_end > w_after)
        yoyo = true;

    //출력
    //다이어트 후 예상 체중, 일일 기초 대사량, 요요 현상 발생 여부 or 사망 예상 여부
    if (danger)
        cout << "Danger Diet" << '\n';
    else {
        cout << w_after << ' ' << l_after << ' ';
        if (yoyo)
            cout << "YOYO";
        else
            cout << "NO";
    }
}