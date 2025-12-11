#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 문제의 최대 범위인 10,000,000
const int MAX_N = 10000000;

// 각 숫자의 가장 작은 소인수(Smallest Prime Factor)를 저장할 배열
// minFactor[i] = i의 가장 작은 소인수
int minFactor[MAX_N + 1];

// 에라토스테네스의 체를 이용하여 SPF(가장 작은 소인수) 미리 계산
void sieve() {
    // 1. 초기화: 모든 수의 SPF를 자기 자신으로 설정
    for (int i = 1; i <= MAX_N; ++i) {
        minFactor[i] = i;
    }

    // 2. 체를 이용하여 SPF 갱신
    for (int i = 2; i * i <= MAX_N; ++i) {
        // i가 소수라면 (아직 갱신되지 않았다면)
        if (minFactor[i] == i) {
            // i의 배수들에 대해 SPF를 i로 설정
            for (int j = i * i; j <= MAX_N; j += i) {
                // 이미 더 작은 소인수로 표시된 적이 없다면 갱신
                if (minFactor[j] == j) {
                    minFactor[j] = i;
                }
            }
        }
    }
}

// 소인수분해를 이용해 약수의 개수를 빠르게 구하는 함수
int getDivisorCount(int n) {
    if (n == 1) return 1;

    int count = 1;
    
    // n이 1이 될 때까지 소인수로 계속 나눔
    while (n > 1) {
        int prime = minFactor[n]; // 현재 n의 가장 작은 소인수
        int exponent = 0;
        
        // 해당 소인수로 나누어 떨어지는 동안 반복 (지수 계산)
        while (n % prime == 0) {
            exponent++;
            n /= prime;
        }
        
        // 약수 개수 공식: (지수 + 1)을 곱해줌
        count *= (exponent + 1);
    }
    return count;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. 전처리: 10,000,000까지의 모든 수에 대해 SPF 계산
    sieve();

    int C;
    if (cin >> C) {
        while (C--) {
            int L, U;
            cin >> L >> U;

            int maxDivisors = 0;
            
            // 2. L부터 U까지 각 숫자의 약수 개수를 구하고 최댓값 갱신
            for (int i = L; i <= U; ++i) {
                int currentDivisors = getDivisorCount(i);
                if (currentDivisors > maxDivisors) {
                    maxDivisors = currentDivisors;
                }
            }
            
            cout << maxDivisors << "\n";
        }
    }

    return 0;
}