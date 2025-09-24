#include <iostream>
#include <vector>
#include <algorithm> // max, next_permutation 함수를 사용하기 위해

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // N번의 게임 결과를 미리 저장
    vector<pair<int, int>> games(N);
    for (int i = 0; i < N; ++i) {
        cin >> games[i].first >> games[i].second;
    }

    int max_wins = 0;

    // p 배열은 숫자 1, 2, 3이 무엇을 의미하는지에 대한 매핑
    // p[0]=발굽, p[1]=종이, p[2]=가위 라고 가정
    vector<int> p = {1, 2, 3};

    // next_permutation을 이용해 6가지 모든 매핑을 순회
    do {
        int Hoof = p[0];
        int Paper = p[1];
        int Scissors = p[2];

        int current_wins = 0;
        // 저장된 게임들에 현재 매핑을 적용해 승리 횟수 계산
        for (const auto& game : games) {
            int p1_move = game.first;
            int p2_move = game.second;

            // 플레이어 1이 이기는 조건 (발굽>가위, 종이>발굽, 가위>종이)
            if ((p1_move == Hoof && p2_move == Scissors) ||
                (p1_move == Paper && p2_move == Hoof) ||
                (p1_move == Scissors && p2_move == Paper)) {
                current_wins++;
            }
        }
        
        // 지금까지의 최다 승리 횟수와 비교하여 갱신
        max_wins = max(max_wins, current_wins);

    } while (next_permutation(p.begin(), p.end()));

    cout << max_wins << endl;

    return 0;
}