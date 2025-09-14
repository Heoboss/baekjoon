#include <iostream>
#include <algorithm> // min 함수를 사용하기 위해

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    // x축 방향의 최단 거리 (왼쪽, 오른쪽 경계선까지)
    int min_x_dist = min(x, w - x);

    // y축 방향의 최단 거리 (아래쪽, 위쪽 경계선까지)
    int min_y_dist = min(y, h - y);

    // 두 방향의 최단 거리 중 더 짧은 값을 출력
    cout << min(min_x_dist, min_y_dist) << endl;

    return 0;
}