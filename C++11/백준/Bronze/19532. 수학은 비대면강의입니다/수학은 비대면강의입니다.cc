#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    // x와 y의 범위를 -999부터 999까지 모두 확인
    for (int x = -999; x <= 999; ++x) {
        for (int y = -999; y <= 999; ++y) {
            // 두 방정식을 모두 만족하는지 확인
            if ((a * x + b * y == c) && (d * x + e * y == f)) {
                cout << x << " " << y << endl;
                return 0; // 답을 찾았으므로 즉시 종료
            }
        }
    }

    return 0;
}