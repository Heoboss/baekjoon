#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
#include <map>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int group_num = 1;
    while (true) {
        int N;
        cin >> N;
        if (N == 0) {
            break;
        }
        // cin >> N 이후의 개행 문자를 무시하기 위해 사용
        cin.ignore();

        // nasty_messages[i]는 i번 학생에게 'N'을 보낸 사람들의 이름을 저장
        vector<vector<int>> nasty_messages(N);
        bool was_nasty = false;

        vector<string> names(N);
        for (int i = 0; i < N; ++i) {
            cin >> names[i];
            for (int j = 0; j < N - 1; j++) {
                // N-1개의 메시지를 하나씩 읽음
                char msg;
                cin >> msg;
                if (msg == 'N') {
                    was_nasty = true;
                    // 나에게 누가 나쁜말을 보냈는지 index를 저장
                    int sender_idx = (i - (j + 1) + N) % N;
                    nasty_messages[i].push_back(sender_idx);
                }
            }

        }


        cout << "Group " << group_num << "\n";
        if (!was_nasty) {
            cout << "Nobody was nasty\n";
        }
        else {
            for (int i = 0; i < N; i++) {
                if (!nasty_messages[i].empty()) {
                    for (auto idx : nasty_messages[i]) {
                        cout << names[idx] << " was nasty about " << names[i] << "\n";
                    }
                }
            }
        }
        cout << "\n";
        group_num++;
    }

    return 0;
}