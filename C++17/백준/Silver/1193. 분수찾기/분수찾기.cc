#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;

    int n = 1;
    int sum = 0;

    // X번째 수가 몇 번째 대각선(n)에 있는지 찾기
    while (sum + n < X) {
        sum += n;
        n++;
    }

    int pos = X - sum; // 해당 대각선에서 몇 번째인지

    int numerator, denominator;
    if (n % 2 == 0) {
        numerator = pos;
        denominator = n - pos + 1;
    } else {
        numerator = n - pos + 1;
        denominator = pos;
    }

    cout << numerator << '/' << denominator << '\n';

    return 0;
}
