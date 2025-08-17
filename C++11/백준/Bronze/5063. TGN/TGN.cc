#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    while (N--) {
        int r, e, c;
        cin >> r >> e >> c;

        int profit_with_ad = e - c;

        if (profit_with_ad > r) {
            cout << "advertise\n";
        } else if (profit_with_ad < r) {
            cout << "do not advertise\n";
        } else {
            cout << "does not matter\n";
        }
    }

    return 0;
}