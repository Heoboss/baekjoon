#include <iostream>
#include <vector>
#include <algorithm> // max_element 사용을 위해

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s, k;
    // n: 구간의 개수, s: 구간의 크기, k: 데이터의 개수
    if (cin >> n >> s >> k) {
        // 각 구간별 데이터 개수를 저장할 벡터 (0으로 초기화)
        vector<int> bins(n, 0);

        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            
            // 데이터 x가 속하는 구간의 인덱스 계산
            // 값은 1부터 시작하므로 1을 뺀 뒤 s로 나눔
            int index = (x - 1) / s;

            // 유효한 인덱스 범위 내에 있다면 카운트 증가
            if (index >= 0 && index < n) {
                bins[index]++;
            }
        }

        // 가장 데이터가 많은 구간의 개수(최대 높이) 구하기
        int max_h = 0;
        for (int count : bins) {
            if (count > max_h) {
                max_h = count;
            }
        }

        // 히스토그램 그리기 (위에서부터 아래로)
        // 높이 h가 max_h일 때부터 1일 때까지 반복
        for (int h = max_h; h >= 1; --h) {
            for (int i = 0; i < n; ++i) {
                // 해당 구간의 데이터 개수가 현재 높이 h 이상이면 # 출력
                if (bins[i] >= h) {
                    cout << "#";
                } else {
                    // 아니면 빈 공간을 채우는 . 출력
                    cout << ".";
                }
            }
            // 한 행이 끝나면 줄바꿈
            cout << "\n";
        }

        // 마지막 바닥 라인 출력 (-)
        for (int i = 0; i < n; ++i) {
            cout << "-";
        }
        cout << "\n";
    }

    return 0;
}