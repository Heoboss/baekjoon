#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;

    while (true) {
        cin >> a >> b;

        // 종료 조건
        if (a == 0 && b == 0) {
            break;
        }

        // a가 b의 약수인 경우 (b가 a의 배수인 경우)
        if (b % a == 0) {
            cout << "factor\n";
        }
        // a가 b의 배수인 경우 (a가 b로 나누어 떨어지는 경우)
        else if (a % b == 0) {
            cout << "multiple\n";
        }
        // 둘 다 아닌 경우
        else {
            cout << "neither\n";
        }
    }

    return 0;
}