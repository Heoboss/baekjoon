#include <iostream>
#include <cmath> // pow 함수를 사용하기 위해

using namespace std;

void solve() {
    int k;
    cin >> k;

    // 2^k - 1 계산
    // pow 함수는 double을 반환하므로 정수로 형변환
    int result = static_cast<int>(pow(2, k)) - 1;
    
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}