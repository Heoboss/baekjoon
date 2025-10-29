#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    cin >> A >> B;

    int count = 1;
    bool possible = true;

    while (A < B) {
        // B의 마지막 자리가 1인 경우
        if (B % 10 == 1) {
            B = (B - 1) / 10;
        }
        // B가 짝수인 경우
        else if (B % 2 == 0) {
            B = B / 2;
        }
        // 위 두 경우가 모두 아니면 불가능
        else {
            possible = false;
            break;
        }
        count++;
    }

    if (possible && A == B) {
        cout << count << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}