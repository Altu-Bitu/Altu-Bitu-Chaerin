//
// Created by 김채린 on 2021/11/23.
//

#include <iostream>
#include <vector>

using namespace std;

// 전위순회 결과를 입력받아 후위순회 결과를 구해서 출력하는 함수
void postorder(int left, int right, vector<int> &nodes) {

    // 기저조건 : 왼쪽 경계가 오른쪽 경계 너머에 있음
    if (left > right)
        return;

    // idx : 처음으로 root 노드보다 값이 커지는 위치
    int idx = right + 1;

    // left부터 right까지 차례로 확인하며
    for (int i = left; i <= right; i++) {
        // root보다 값이 커지는 순간
        if (nodes[i] > nodes[left]) {
            // idx 값(왼쪽 서브트리와 오른쪽 서브트리의 경계) 갱신
            idx = i;
            // 반복문 탈출
            break;
        }
    }

    // 왼쪽 서브트리에 대해서 재귀
    postorder(left + 1, idx - 1, nodes);
    // 오른쪽 서브트리에 대해서 재귀
    postorder(idx, right, nodes);
    // 출력
    cout << nodes[left] << '\n';
}

/**
 * 분할 정복 - 4256번 참고
 *
 * 분할 정복 풀이
 * 1. 전위 순회는 root 노드의 위치는 알 수 있지만 왼쪽, 오른쪽 서브트리의 경계는 알 수 없음
 * 2. BST의 성질 : 왼쪽 서브트리의 모든 노드 값 < 루트 노드 값 < 오른쪽 서브트리의 모든 노드 값
 *    -> 처음으로 root 보다 값이 커진다면, 그 위치가 왼쪽, 오른쪽 서브트리의 경계
 * 3. 재귀함수 호출로 분할 반복하며 출력
 */

int main() {

    // 입력값을 저장할 변수
    int input;

    // 트리를 전위 순회한 결과를 저장할 벡터
    vector<int> nodes;

    // 입력 (입력이 끝날 때 까지 계속 입력받기)
    while (cin >> input)
        // 입력받은 숫자를 nodes 벡터에 차례로 추가
        nodes.push_back(input);

    // 연산 & 출력
    postorder(0, nodes.size() - 1, nodes);

}