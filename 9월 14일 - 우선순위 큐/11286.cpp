//
// Created by 김채린 on 2021/09/20.
//

#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main(){
    int n, x;
    cin >> n;

    while (n--){
        cin >> x;
        if (x != 0){
            pair tmp = make_pair(abs(x), x);
            pq.push(tmp);
        }
        else {
            if (pq.empty())
                cout << 0 << '\n';
            else {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        }
    }

}