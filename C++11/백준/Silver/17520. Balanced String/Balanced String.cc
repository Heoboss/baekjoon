#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 16769023;

// 분할 정복을 이용한 거듭제곱 함수 (a^b % mod)
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    // 지수 계산: (n + 1) / 2
    ll exponent = (n + 1) / 2;

    // 2^exponent % MOD 계산
    cout << power(2, exponent) << endl;

    return 0;
}