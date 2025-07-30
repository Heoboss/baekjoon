#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int attack[2][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // 배열 초기화
    memset(attack, 0, sizeof(attack));

    // 첫 번째 개 공격 시간 채우기
    for (int k = 0; k < 1001; k += a + b) {
        int endTime = min(1001, k + a);
        fill(attack[0] + k, attack[0] + endTime, 1);
    }

    // 두 번째 개 공격 시간 채우기
    for (int k = 0; k < 1001; k += c + d) {
        int endTime = min(1001, k + c);
        fill(attack[1] + k, attack[1] + endTime, 1);
    }

    // 세 사람 도착 시간 체크
    for (int i = 0; i < 3; i++) {
        int arrived;
        cin >> arrived;
        int cnt = 0;

        if (attack[0][arrived - 1]) cnt++;
        if (attack[1][arrived - 1]) cnt++;

        cout << cnt << '\n';
    }
}
