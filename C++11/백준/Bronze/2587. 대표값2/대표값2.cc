#include <iostream>
#include <vector>
#include <numeric>   // accumulate 함수를 사용하기 위해
#include <algorithm> // sort 함수를 사용하기 위해

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums(5);
    int sum = 0;

    // 5개의 숫자를 입력받아 vector에 저장하고 합계를 구함
    for (int i = 0; i < 5; ++i) {
        cin >> nums[i];
        sum += nums[i];
    }

    // 1. 평균 계산
    int average = sum / 5;

    // 2. 중앙값을 찾기 위해 정렬
    sort(nums.begin(), nums.end());

    // 5개 중 3번째 값(인덱스 2)이 중앙값
    int median = nums[2];

    // 결과 출력
    cout << average << "\n";
    cout << median << "\n";

    return 0;
}