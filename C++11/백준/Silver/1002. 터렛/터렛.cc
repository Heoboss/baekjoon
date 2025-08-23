#include <iostream>
#include <cmath>

using namespace std;

void solve() {
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    // 두 중심 사이의 거리의 제곱 계산
    double d_sq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

    // 반지름 합의 제곱과 차의 제곱 계산
    double r_sum_sq = (r1 + r2) * (r1 + r2);
    double r_diff_sq = (r1 - r2) * (r1 - r2);

    // Case 1: 두 원이 일치하여 교점이 무한대인 경우
    if (d_sq == 0 && r_diff_sq == 0) {
        cout << -1 << '\n';
    }
    // Case 2: 두 점에서 만나는 경우
    else if (d_sq > r_diff_sq && d_sq < r_sum_sq) {
        cout << 2 << '\n';
    }
    // Case 3: 한 점에서 만나는 경우 (외접 또는 내접)
    else if (d_sq == r_sum_sq || (d_sq == r_diff_sq && d_sq != 0)) {
        cout << 1 << '\n';
    }
    // Case 4: 만나지 않는 경우
    else {
        cout << 0 << '\n';
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