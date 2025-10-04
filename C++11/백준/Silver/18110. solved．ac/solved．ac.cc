#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <cmath>     // round
#include <numeric>   // accumulate

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    // 1. 제외할 인원 계산 (15%를 반올림)
    int trimmed_count = round(n * 0.15);

    vector<int> opinions(n);
    for (int i = 0; i < n; ++i) {
        cin >> opinions[i];
    }

    // 2. 의견 정렬
    sort(opinions.begin(), opinions.end());

    double sum = 0;
    int count = 0;

    // 3. 절사평균 계산을 위한 합계 구하기
    // 앞에서 trimmed_count개, 뒤에서 trimmed_count개를 제외하고 더함
    for (int i = trimmed_count; i < n - trimmed_count; ++i) {
        sum += opinions[i];
        count++;
    }

    // 4. 최종 평균을 계산하고 반올림
    int final_score = round(sum / count);

    cout << final_score << endl;

    return 0;
}