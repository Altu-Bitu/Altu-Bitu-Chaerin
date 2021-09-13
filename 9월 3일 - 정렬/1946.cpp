//
// Created by 김채린 on 2021/09/09.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct score {
    int document;
    int interview;
};

vector<int> result;
vector<score> arr;

bool cmp(const score &i1, const score &i2) {
    return i1.document < i2.document;
}

//서류심사성적순으로 나열한 상태에서 면접 성적만 비교
//서류심사성적이 좋은 사람의 면접 성적을 interview_best에 저장
//차례로 내려가며 interview_best보다 더 좋은 면접 성적을 받은 사람만 채용
//interview_best 갱신
int cnt(int n) {
    int sum = 0;
    int interview_best = n+1;
    for (int i = 0; i < n; i++) {
        if (interview_best > arr[i].interview){
            interview_best = arr[i].interview;
            sum++;
        }
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    result.assign(t, 0);
    for (int i = 0; i < t; i++) {    // 각 테스트케이스
        int n;
        cin >> n;
        arr.assign(n, {});
        for (int j = 0; j < n; j++) {    //각 면접자
            cin >> arr[j].document >> arr[j].interview;
        }
        sort(arr.begin(), arr.end(), cmp);    //서류심사성적순으로 정렬
        result[i] = cnt(n);
    }

    //출력
    for (int i = 0; i < t; i++)
        cout << result[i] << '\n';
}
