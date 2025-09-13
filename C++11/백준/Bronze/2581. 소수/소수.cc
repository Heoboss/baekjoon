#include <iostream>
#include <cmath> // sqrt 함수를 사용하기 위해

using namespace std;

// 소수인지 판별하는 함수
bool isPrime(int num) {
    // 1은 소수가 아님
    if (num < 2) {
        return false;
    }
    // 2부터 num의 제곱근까지만 확인하면 됨
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false; // 나누어 떨어지면 소수가 아님
        }
    }
    return true; // 나누어 떨어지지 않으면 소수
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    long long sum_of_primes = 0;
    int min_prime = -1;

    // M부터 N까지의 모든 수를 확인
    for (int i = M; i <= N; ++i) {
        if (isPrime(i)) {
            sum_of_primes += i;
            // 첫 번째로 발견된 소수가 최솟값임
            if (min_prime == -1) {
                min_prime = i;
            }
        }
    }

    // 범위 내에 소수가 없는 경우
    if (sum_of_primes == 0) {
        cout << -1 << endl;
    } else {
        cout << sum_of_primes << endl;
        cout << min_prime << endl;
    }

    return 0;
}