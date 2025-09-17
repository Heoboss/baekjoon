#include <iostream>

using namespace std;

void solve() {
    int N;
    double D; // 거리는 실수일 수 있으므로 double 사용
    cin >> N >> D;

    int capable_spaceships = 0;
    for (int i = 0; i < N; ++i) {
        double v, f, c; // 속도, 연료량, 연비
        cin >> v >> f >> c;

        // 우주선이 갈 수 있는 최대 거리 계산
        // 최대 비행 시간 = f / c
        // 최대 이동 거리 = v * (f / c)
        double max_distance = v * (f / c);

        if (max_distance >= D) {
            capable_spaceships++;
        }
    }
    cout << capable_spaceships << "\n";
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