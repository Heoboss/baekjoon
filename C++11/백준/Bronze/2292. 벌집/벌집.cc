#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // N이 1인 경우는 1개의 방만 지나므로 항상 1
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    int path_length = 1;
    long long max_room_in_layer = 1;

    while (max_room_in_layer < N) {
        // 다음 겹을 추가. 현재 경로 길이(겹 번호)에 6을 곱한 만큼 방이 늘어남
        max_room_in_layer += 6LL * path_length;
        path_length++;
    }

    cout << path_length << endl;

    return 0;
}
