#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string N;
    int B;
    cin >> N >> B;
    int result = 0;
    for (int i = 0; i < N.length(); ++i) {
        char c = N[i];
        int digit_value;
        if (c >= '0' && c <= '9') {
            digit_value = c - '0';
        }
        else {
            digit_value = c - 'A' + 10;
        }
        result = result * B + digit_value;
    }
    cout << result << endl;
    return 0;
}