//
// Created by 김채린 on 2021/12/05.
//

// 참고 : https://tech.kakao.com/2020/04/01/2019-internship-test/

#include <string>
#include <vector>
#include <map>

using namespace std;

// 다음 빈 방의 정보를 저장할 벡터 (0 : 빈 방)
map<long long, long long> rooms;

long long nextRoom(long long input){
    // 원하는 방이 비어있으면
    if (rooms[input] == 0)
        // 원하는 방 제공
        return input;
        // 원하는 방이 비어있지 않으면
    else
        // 다음 빈 방 찾기
        return rooms[input] = nextRoom(rooms[input]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    // 입력을 차례로 처리
    for (long long i=0; i<room_number.size(); i++){
        // 들어갈 수 있는 방 번호를
        long long next_room = nextRoom(room_number[i]);
        // answer에 push
        answer.push_back(next_room);
        // 해당 방에 방금 사람이 들어갔으므로 그 방의 다음 방을 가리키도록
        rooms[next_room] = next_room + 1;
    }
    return answer;
}