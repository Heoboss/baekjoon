#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B, C;
    cin >> A >> B >> C;

    // ⚠️ 손익분기점이 존재하지 않는 경우
    // 판매 가격이 가변 비용보다 낮거나 같으면 이익이 발생할 수 없음
    if (B >= C) {
        cout << -1 << endl;
    }
    // ✅ 손익분기점이 존재하는 경우
    else {
        // n > A / (C - B) 를 만족하는 최소 정수 n
        cout << A / (C - B) + 1 << endl;
    }

    return 0;
}