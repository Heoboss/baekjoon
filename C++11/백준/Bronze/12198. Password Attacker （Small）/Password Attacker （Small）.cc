#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

// 거듭제곱 (a^b mod MOD)
long long power(long long a, long long b) {
    long long result = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return result;
}

// 이항계수 C(n, r)
long long binomial(int n, int r) {
    if (r > n || r < 0) return 0;
    if (r == 0 || r == n) return 1;
    
    long long num = 1, den = 1;
    for (int i = 0; i < r; i++) {
        num = (num * (n - i)) % MOD;
        den = (den * (i + 1)) % MOD;
    }
    
    // 모듈러 역원을 이용한 나눗셈
    return (num * power(den, MOD - 2)) % MOD;
}

int main() {
    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; tc++) {
        int M, N;
        cin >> M >> N;
        
        long long answer = 0;
        
        // 포함-배제 원리 적용
        for (int i = 0; i < M; i++) {
            long long sign = (i % 2 == 0) ? 1 : -1;
            long long comb = binomial(M, i);
            long long pow_val = power(M - i, N);
            
            long long term = (comb * pow_val) % MOD;
            answer = (answer + sign * term) % MOD;
        }
        
        // 음수 방지
        answer = (answer % MOD + MOD) % MOD;
        
        cout << "Case #" << tc << ": " << answer << endl;
    }
    
    return 0;
}