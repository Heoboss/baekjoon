#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		int n = sqrt(N);

		cout << (int)(n * n == N) << '\n';
	}

	return 0;
}