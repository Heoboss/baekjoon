#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    deque<int> d;
    for (int i = 0; i < N; ++i) {
        int command;
        cin >> command;

        switch (command) {
            case 1: {
                int x;
                cin >> x;
                d.push_front(x);
                break;
            }
            case 2: {
                int x;
                cin >> x;
                d.push_back(x);
                break;
            }
            case 3: {
                if (!d.empty()) {
                    cout << d.front() << "\n";
                    d.pop_front();
                } else {
                    cout << -1 << "\n";
                }
                break;
            }
            case 4: {
                if (!d.empty()) {
                    cout << d.back() << "\n";
                    d.pop_back();
                } else {
                    cout << -1 << "\n";
                }
                break;
            }
            case 5: {
                cout << d.size() << "\n";
                break;
            }
            case 6: {
                cout << (d.empty() ? 1 : 0) << "\n";
                break;
            }
            case 7: {
                if (!d.empty()) {
                    cout << d.front() << "\n";
                } else {
                    cout << -1 << "\n";
                }
                break;
            }
            case 8: {
                if (!d.empty()) {
                    cout << d.back() << "\n";
                } else {
                    cout << -1 << "\n";
                }
                break;
            }
        }
    }

    return 0;
}