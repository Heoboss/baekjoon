#include <iostream>
#include <vector>
#include <numeric> // accumulate를 사용하기 위해
#include <algorithm> // sort를 사용하기 위해

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        }

        vector<int> divisors;
        int sum = 0;

        // 1부터 n-1까지 확인하며 약수와 그 합을 구함
        for (int i = 1; i < n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                sum += i;
            }
        }

        // 약수들의 합이 n과 같은지 판별
        if (sum == n) {
            cout << n << " = ";
            for (size_t i = 0; i < divisors.size(); ++i) {
                cout << divisors[i];
                if (i != divisors.size() - 1) {
                    cout << " + ";
                }
            }
            cout << "\n";
        } else {
            cout << n << " is NOT perfect.\n";
        }
    }

    return 0;
}