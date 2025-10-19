#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <tuple>
using namespace std;
int n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	// dp[i] : i원을 만드는 데 필요한 최소 동전 개수
	vector<int> dp(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		// 1원 사용하는 경우
		dp[i] = dp[i - 1] + 1;
		
		// 2원 사용하는 것이 이득인지 확인
		if (i >= 2) {
			dp[i] = min(dp[i], dp[i - 2] + 1);
		}

		// 5원 사용하는 것이 이득인지 확인
		if (i >= 5) {
			dp[i] = min(dp[i], dp[i - 5] + 1);
		}

		// 7원 사용하는 것이 이득인지 확인
		if (i >= 7) {
			dp[i] = min(dp[i], dp[i - 7] + 1);
		}
	}

	cout << dp[n];

	return 0;
}