#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, M, A, B; // A, B와 계산 결과가 클 수 있으므로 long long 사용
    cin >> N >> M >> A >> B;

    // 1. 필요한 총 의자 수
    long long total_needed = N * 3;

    // 2. 이미 충분한 의자를 가졌는지 확인
    if (M >= total_needed) {
        cout << 0 << endl;
    } else {
        // 3. 부족한 의자 수 계산
        long long chairs_to_buy = total_needed - M;
        
        // 4. 총비용 계산 및 출력
        long long cost = (chairs_to_buy * A) + B;
        cout << cost << endl;
    }

    return 0;
}