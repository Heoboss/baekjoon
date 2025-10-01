#include <iostream>
#include <vector>
#include <algorithm> // sort 함수를 사용하기 위해
#include <functional> // greater<>를 사용하기 위해

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, k;
    cin >> N >> k;

    vector<int> scores(N);
    for (int i = 0; i < N; ++i) {
        cin >> scores[i];
    }

    // 점수를 내림차순으로 정렬
    sort(scores.begin(), scores.end(), greater<int>());

    // k번째 점수(인덱스는 k-1)가 커트라인
    cout << scores[k - 1] << endl;

    return 0;
}