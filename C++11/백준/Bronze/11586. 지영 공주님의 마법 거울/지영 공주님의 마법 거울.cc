#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<string> mirror(N);
    for (int i = 0; i < N; ++i) {
        cin >> mirror[i];
    }

    int K;
    cin >> K;

    if (K == 1) {
        // Case 1: 그대로 출력
        for (int i = 0; i < N; ++i) {
            cout << mirror[i] << "\n";
        }
    } else if (K == 2) {
        // Case 2: 좌우 반전
        for (int i = 0; i < N; ++i) {
            // 각 행을 뒤집어서 출력
            string reversed_row = mirror[i];
            reverse(reversed_row.begin(), reversed_row.end());
            cout << reversed_row << "\n";
        }
    } else if (K == 3) {
        // Case 3: 상하 반전
        // 마지막 행부터 첫 행까지 거꾸로 출력
        for (int i = N - 1; i >= 0; --i) {
            cout << mirror[i] << "\n";
        }
    }

    return 0;
}