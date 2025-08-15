#include <iostream>
#include <vector>
#include <numeric> // std::accumulate를 사용하기 위해

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<long long> pigs(6);
    long long initial_sum = 0;
    for (int i = 0; i < 6; ++i) {
        cin >> pigs[i];
        initial_sum += pigs[i];
    }

    if (initial_sum > N) {
        cout << 1 << "\n";
        return;
    }

    int days = 1;
    while (true) {
        days++;
        
        // 이전 날(어제) 돼지들이 먹은 양을 기준으로
        // 오늘 먹을 양을 계산해야 하므로, 어제의 양을 복사해 둠
        vector<long long> prev_day_eaten = pigs;

        // 오늘 각 돼지가 먹을 양을 계산
        for (int i = 0; i < 6; ++i) {
            long long today_eaten = 0;
            // 양 옆과 대각선 돼지들이 어제 먹은 양의 합
            // 원형으로 연결되어 있으므로 % 6 연산 사용
            today_eaten += prev_day_eaten[i];                 // 자기 자신
            today_eaten += prev_day_eaten[(i + 1) % 6];       // 오른쪽
            today_eaten += prev_day_eaten[(i + 5) % 6];       // 왼쪽
            today_eaten += prev_day_eaten[(i + 3) % 6];       // 맞은편
            pigs[i] = today_eaten;
        }

        // 오늘 먹은 양의 총합을 구함
        long long total_eaten_today = 0;
        for (int i = 0; i < 6; ++i) {
            total_eaten_today += pigs[i];
        }

        // 만약 오늘 먹은 총량이 목표치를 넘었다면 종료
        if (total_eaten_today > N) {
            cout << days << "\n";
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}