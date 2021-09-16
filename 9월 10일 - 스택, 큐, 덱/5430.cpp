//
// Created by 김채린 on 2021/09/16.
//

#include <iostream>
#include <deque>

using namespace std;

int main() {
    int t, n;
    string cmd, num_arr;
    bool backward;
    bool error;
    deque<int> dq;

    cin >> t;
    while (t--) {
        //입력
        cin >> cmd;
        cin >> n;
        cin >> num_arr;
        dq.clear();
        backward = false;
        error = false;
        string tmp;
        for (int i = 0; i < num_arr.length(); i++) {
            if (num_arr[i] == '[')
                continue;
            else if ('0' <= num_arr[i] && num_arr[i] <= '9')
                tmp += num_arr[i];
            else if (num_arr[i] == ',' || num_arr[i] == ']') {
                if (!tmp.empty()) {
                    dq.push_back(stoi(tmp));
                    tmp = "";
                }
            }
        }

        //언산
        for (int i = 0; i < cmd.length(); i++) {
            switch (cmd[i]) {
                case 'R':
                    backward = !backward;
                    break;
                case 'D':
                    if (backward) {
                        if (dq.empty())
                            error = true;
                        else
                            dq.pop_back();
                    } else {
                        if (dq.empty())
                            error = true;
                        else
                            dq.pop_front();
                    }
                    break;
            }
        }

        //출력
        if (error)
            cout << "error\n";
        else {
            if (backward) {
                cout << '[';
                for (int i = dq.size() - 1; i > 0; i--)
                    cout << dq[i] << ',';
                cout << dq[0] << ']' << '\n';
            } else {
                cout << '[';
                for (int i = 0; i < dq.size() - 1; i++)
                    cout << dq[i] << ',';
                cout << dq[dq.size() - 1] << ']' << '\n';
            }
        }
    }
    return 0;
}