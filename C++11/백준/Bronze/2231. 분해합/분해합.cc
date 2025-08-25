#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // N의 생성자를 찾기 위해 1부터 N까지 순회
    for (int i = 1; i < N; ++i) {
        int sum_of_digits = 0;
        int current_num = i;

        // i의 각 자릿수의 합을 구함
        while (current_num != 0) {
            sum_of_digits += current_num % 10; // 마지막 자릿수를 더함
            current_num /= 10;                  // 마지막 자릿수를 제거
        }

        // 분해합이 N과 같은지 확인
        if (i + sum_of_digits == N) {
            cout << i; // 가장 작은 생성자를 찾았으므로 출력하고 종료
            return 0;
        }
    }

    // 반복문이 끝날 때까지 생성자를 찾지 못한 경우
    cout << 0;
    return 0;
}
