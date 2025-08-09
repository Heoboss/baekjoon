#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    stack<int> s;

    for (int i = 0; i < N; ++i) {
        int command;
        cin >> command;

        switch (command) {
        case 1: {
            int x;
            cin >> x;
            s.push(x);
            break;
        }
        case 2: {
            if (!s.empty()) {
                cout << s.top() << "\n";
                s.pop();
            }
            else {
                cout << -1 << "\n";
            }
            break;
        }
        case 3: {
            cout << s.size() << "\n";
            break;
        }
        case 4: {
            cout << (s.empty() ? 1 : 0) << "\n";
            break;
        }
        case 5: {
            if (!s.empty()) {
                cout << s.top() << "\n";
            }
            else {
                cout << -1 << "\n";
            }
            break;
        }
        }
    }

    return 0;
}