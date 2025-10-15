#include <iostream>
#include <algorithm> // min 함수를 사용하기 위해
#include <limits>    // INT_MAX를 사용하기 위해

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 512kg 이상인 합계 중 최솟값을 저장할 변수
    // 나올 수 없는 아주 큰 값으로 초기화
    int min_sum_above_512 = numeric_limits<int>::max();

    for (int i = 0; i < N; ++i) {
        int bench, squat, deadlift;
        cin >> bench >> squat >> deadlift;

        int current_sum = bench + squat + deadlift;

        // 합계가 512 이상인 경우
        if (current_sum >= 512) {
            // 현재까지의 최솟값과 비교하여 갱신
            min_sum_above_512 = min(min_sum_above_512, current_sum);
        }
    }

    // 512kg 이상인 학생이 한 명도 없었다면
    if (min_sum_above_512 == numeric_limits<int>::max()) {
        cout << -1 << endl;
    } else {
        cout << min_sum_above_512 << endl;
    }

    return 0;
}