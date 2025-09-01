#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

void solve() {
    string p, arr_str;
    int n;
    cin >> p >> n >> arr_str;

    deque<int> d;
    if (n > 0) {
        // 대괄호 제거
        arr_str = arr_str.substr(1, arr_str.length() - 2);
        stringstream ss(arr_str);
        string temp;
        while (getline(ss, temp, ',')) {
            d.push_back(stoi(temp));
        }
    }

    bool is_reversed = false;
    bool error_flag = false;

    for (char cmd : p) {
        if (cmd == 'R') {
            is_reversed = !is_reversed; // 플래그만 변경
        }
        else { // 'D'
            if (d.empty()) {
                error_flag = true;
                break;
            }
            if (is_reversed) {
                d.pop_back(); // 뒤집혔을 땐 뒤에서 삭제
            }
            else {
                d.pop_front(); // 아니면 앞에서 삭제
            }
        }
    }

    if (error_flag) {
        cout << "error\n";
    }
    else {
        cout << "[";
        // 최종 방향에 맞게 출력
        if (is_reversed) {
            reverse(d.begin(), d.end());
        }

        for (int i = 0; i < d.size(); ++i) {
            cout << d[i];
            if (i != d.size() - 1) {
                cout << ",";
            }
        }
        cout << "]\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}