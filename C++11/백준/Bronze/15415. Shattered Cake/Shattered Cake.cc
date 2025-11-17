#include <iostream>

using namespace std;

int main() {
    // 입출력 속도 향상 (필수)
    // N이 최대 5,000,000이므로 이 설정이 없으면 시간 초과가 날 수 있습니다.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int W; // 원래 케이크의 너비
    cin >> W;

    int N; // 조각의 개수
    cin >> N;

    long long total_area = 0; // 전체 넓이 합 (오버플로우 방지 위해 long long)

    for (int i = 0; i < N; ++i) {
        int w, l;
        cin >> w >> l;
        // 각 조각의 넓이를 더함
        total_area += (long long)w * l;
    }

    // 원래 길이 L = 전체 넓이 / 너비 W
    cout << total_area / W << "\n";

    return 0;
}