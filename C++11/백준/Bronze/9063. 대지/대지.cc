#include <iostream>
#include <algorithm> // min, max 함수를 사용하기 위해

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 점이 0개 또는 1개이면 넓이는 0
    if (N <= 1) {
        cout << 0 << endl;
        return 0;
    }

    // 최솟값/최댓값을 저장할 변수 초기화
    // 첫 번째 점의 좌표로 초기화
    int min_x, max_x, min_y, max_y;
    int x, y;
    cin >> x >> y;
    min_x = max_x = x;
    min_y = max_y = y;

    // 나머지 N-1개의 점을 읽으면서 최솟값/최댓값 갱신
    for (int i = 1; i < N; ++i) {
        cin >> x >> y;
        min_x = min(min_x, x);
        max_x = max(max_x, x);
        min_y = min(min_y, y);
        max_y = max(max_y, y);
    }

    // 넓이 계산 및 출력
    long long width = max_x - min_x;
    long long height = max_y - min_y;
    cout << width * height << endl;

    return 0;
}