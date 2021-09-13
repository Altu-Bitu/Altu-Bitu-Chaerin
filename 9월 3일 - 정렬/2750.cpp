//
// Created by 김채린 on 2021/09/07.
//

#include <iostream>
#include <vector>

using namespace std;

//정렬할 배열
vector<int> arr;

//버블 정렬
void bubbleSort(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
}

//향상된 버블 정렬
void bubbleSortAdv(int n) {
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 1; j < n - i; j++) {
            if (arr[j - 1] > arr[j]) {
                flag = false;
                swap(arr[j - 1], arr[j]);
            }
        }
        if (flag)
            break;
    }
}

int main() {
    int n;

    //입력
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //연산
    //bubbleSort(n);
    bubbleSortAdv(n);

    //출력
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}