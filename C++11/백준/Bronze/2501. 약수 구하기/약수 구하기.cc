#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    int count = 0; // 찾은 약수의 개수를 세는 변수

    // 1부터 N까지 순회하며 약수를 찾음
    for (int i = 1; i <= N; ++i) {
        // i가 N의 약수인지 확인
        if (N % i == 0) {
            count++;
        }

        // K번째 약수를 찾았으면
        if (count == K) {
            cout << i << endl; // 해당 약수를 출력하고
            return 0;          // 프로그램을 종료
        }
    }

    // 반복문이 끝날 때까지 K번째 약수를 찾지 못한 경우
    cout << 0 << endl;

    return 0;
}