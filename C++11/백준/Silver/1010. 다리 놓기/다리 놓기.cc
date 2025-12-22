#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;


	for (int i = 0; i < T; i++) {
		int n, m;
		cin >> n >> m;

		long answer = 1;
		int k = 1;
		for (int j = m; j > m - n; j--) {
			answer *= j;
			answer /= k;
			k++;
		}

		cout << answer << "\n";
	}
	return 0;
}