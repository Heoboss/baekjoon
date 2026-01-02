#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool chk = 1;
	int N, M; cin >> N >> M;
	while (M--) {
		int K; cin >> K;
		int old = N + 1;
		while (K--) {
			int x; cin >> x;
			if (x > old) chk = 0;
			old = x;
		}
	}
	
	if (chk) cout << "Yes";
	else cout << "No";
}