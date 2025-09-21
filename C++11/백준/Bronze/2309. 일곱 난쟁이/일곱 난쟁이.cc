#include <iostream>
#include <vector>
#include <numeric>   // accumulate 함수를 사용하기 위해
#include <algorithm> // sort 함수를 사용하기 위해

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> heights(9);
    int total_sum = 0;

    // 9명의 키를 입력받고 총합을 계산
    for (int i = 0; i < 9; ++i) {
        cin >> heights[i];
        total_sum += heights[i];
    }

    // 두 가짜 난쟁이의 키 합
    int impostor_sum = total_sum - 100;

    // 두 가짜 난쟁이를 찾기 위한 이중 반복문
    for (int i = 0; i < 8; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            if (heights[i] + heights[j] == impostor_sum) {
                // 가짜 난쟁이 두 명의 키를 0으로 만들어 제외 처리
                heights[i] = 0;
                heights[j] = 0;

                // 키를 오름차순으로 정렬
                sort(heights.begin(), heights.end());

                // 0으로 만든 두 명을 제외하고 나머지 7명의 키 출력
                for (int k = 2; k < 9; ++k) {
                    cout << heights[k] << "\n";
                }
                
                return 0; // 답을 찾았으므로 프로그램 종료
            }
        }
    }

    return 0;
}