#include <iostream>
#include <numeric> // accumulate를 사용할 수도 있습니다.
#include <algorithm> // max를 사용할 수도 있습니다.

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int winner = 0;
    int max_score = 0;

    // 1번부터 5번 참가자까지 반복
    for (int i = 1; i <= 5; ++i) {
        int score1, score2, score3, score4;
        cin >> score1 >> score2 >> score3 >> score4;

        int current_score = score1 + score2 + score3 + score4;

        // 현재 참가자의 점수가 지금까지의 최고점보다 높으면 갱신
        if (current_score > max_score) {
            max_score = current_score;
            winner = i;
        }
    }

    cout << winner << " " << max_score << endl;

    return 0;
}