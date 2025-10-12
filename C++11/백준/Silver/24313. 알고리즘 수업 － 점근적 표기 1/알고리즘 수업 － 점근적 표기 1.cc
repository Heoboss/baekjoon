#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;

    // 두 가지 조건을 모두 만족하는지 확인
    // 1. f(n₀) ≤ c * n₀ (시작점 조건)
    // 2. a₁ ≤ c (기울기 조건)
    if ((a1 * n0 + a0 <= c * n0) && (a1 <= c)) {
        cout << 1 << endl; // 만족
    } else {
        cout << 0 << endl; // 불만족
    }

    return 0;
}