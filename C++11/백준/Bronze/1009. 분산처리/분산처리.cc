#include <iostream>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    int result = 1;
    // We only care about the last digit of a
    a = a % 10;

    // Use a loop to simulate the power calculation,
    // keeping only the last digit at each step.
    for (int i = 0; i < b; ++i) {
        result = (result * a) % 10;
    }

    // Per the problem statement, computer #10 handles data when the result is 0.
    if (result == 0) {
        cout << 10 << '\n';
    } else {
        cout << result << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}