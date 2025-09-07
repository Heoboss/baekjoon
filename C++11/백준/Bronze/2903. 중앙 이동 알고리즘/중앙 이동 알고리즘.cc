#include <iostream>
#include <cmath> // pow 함수를 사용하기 위해

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 1. N번째 단계에서 한 변의 점의 개수를 계산합니다.
    // side_points = 2^N + 1
    // pow 함수는 double을 반환하므로 int로 형변환합니다.
    int side_points = static_cast<int>(pow(2, N)) + 1;

    // 2. 총 점의 개수를 계산합니다. (한 변의 점 개수 * 한 변의 점 개수)
    int total_points = side_points * side_points;

    cout << total_points << endl;

    return 0;
}