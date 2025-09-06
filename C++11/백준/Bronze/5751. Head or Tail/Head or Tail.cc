#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }

        int mary_wins = 0;
        int john_wins = 0;

        for (int i = 0; i < N; ++i) {
            int vote;
            cin >> vote;
            
            // ------------------ 수정된 부분 ------------------
            if (vote == 0) { // 0은 Mary의 득표
                mary_wins++;
            } else { // 1은 John의 득표
                john_wins++;
            }
            // ------------------------------------------------
        }

        cout << "Mary won " << mary_wins << " times and John won " << john_wins << " times\n";
    }

    return 0;
}