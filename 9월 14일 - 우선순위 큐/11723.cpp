//
// Created by 김채린 on 2021/09/20.
//

#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int m, input;
    string str;
    cin >> m;
    set<int> s;
    set<int> all;
    for (int i=1; i<=20; i++)
        all.insert(i);

    while (m--) {
        cin >> str;
        if (str == "add") {
            cin >> input;
            s.insert(input);
        }
        else if (str == "remove") {
            cin >> input;
            s.erase(input);
        } else if (str == "check") {
            cin >> input;
            if (s.find(input) == s.end())
                cout << '0' << '\n';
            else
                cout << '1' << '\n';
        } else if (str == "toggle") {
            cin >> input;
            if (s.find(input) == s.end())
                s.insert(input);
            else
                s.erase(input);
        }
        else if (str == "all") {
            s = all;
        } else if (str == "empty") {
            s.clear();
        }

    }

}