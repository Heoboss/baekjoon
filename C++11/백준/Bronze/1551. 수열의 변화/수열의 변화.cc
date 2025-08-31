#include <iostream>
#include <vector>
#include <string>
#include <sstream> // stringstream을 사용하기 위해

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    string line;
    cin >> line;

    vector<int> sequence;
    stringstream ss(line);
    string temp;

    // 쉼표(,)를 기준으로 문자열을 파싱하여 숫자로 변환 후 vector에 저장
    while (getline(ss, temp, ',')) {
        sequence.push_back(stoi(temp));
    }

    // K번 변환 과정 반복
    for (int i = 0; i < K; ++i) {
        vector<int> next_sequence;
        // B[i] = A[i+1] - A[i] 계산
        for (size_t j = 0; j < sequence.size() - 1; ++j) {
            next_sequence.push_back(sequence[j + 1] - sequence[j]);
        }
        // 기존 수열을 다음 수열로 교체
        sequence = next_sequence;
    }

    // 최종 수열 출력
    for (size_t i = 0; i < sequence.size(); ++i) {
        cout << sequence[i];
        if (i != sequence.size() - 1) { // 마지막 원소가 아니면 쉼표 출력
            cout << ",";
        }
    }
    cout << endl;

    return 0;
}