#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <tuple>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> coins;
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		coins.push_back(value);
	}

	// dp[i] : i원을 만드는 경우의 수
	vector<int> dp(10001, 0);

	// 0원을 만드는 가짓 수는 아무것도 사용하지 않는 1가지
	dp[0] = 1;

	for (int coin : coins) {
		for (int j = coin; j <= k; j++) {
			// j원을 만드려면 j-coin 원을 만든 상태에서 coin을 하나 추가하면 된다.
			dp[j] += dp[j - coin];
		}
	}

	cout << dp[k];
	return 0;
}