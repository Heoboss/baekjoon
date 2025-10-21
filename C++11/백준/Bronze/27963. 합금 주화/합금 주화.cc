#include <iostream>
#include <algorithm> // min, max 함수를 사용하기 위해
#include <iomanip>   // 출력 소수점 설정을 위해

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double d1, d2, x;
    cin >> d1 >> d2 >> x;

    // 더 높은 밀도와 낮은 밀도를 구분
    double d_high = max(d1, d2);
    double d_low = min(d1, d2);

    // 위에서 유도한 공식을 사용하여 최종 밀도 계산
    double alloy_density = 100.0 / ((x / d_high) + ((100.0 - x) / d_low));

    // 출력 형식을 설정하여 결과 출력
    cout << fixed << setprecision(12) << alloy_density << endl;

    return 0;
}