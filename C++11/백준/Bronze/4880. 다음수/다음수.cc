#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a1, a2, a3;

    while (true) {
        cin >> a1 >> a2 >> a3;

        // 종료 조건
        if (a1 == 0 && a2 == 0 && a3 == 0) {
            break;
        }

        // 등차수열(AP) 확인
        if (a2 - a1 == a3 - a2) {
            long long diff = a2 - a1;
            cout << "AP " << a3 + diff << "\n";
        }
        // 등비수열(GP) 확인
        else {
            // a1이 0인 경우를 대비해 나눗셈을 직접 하지 않음
            long long ratio = a2 / a1;
            cout << "GP " << a3 * ratio << "\n";
        }
    }

    return 0;
}