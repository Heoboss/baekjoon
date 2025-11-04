#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	string s; cin >> s;
	bool chk = 1;
	if (N <= 25) cout << s;
	else {
		for (int i = 12; i < N - 12; i++) {
			if (s[i] == '.') chk = 0;
		}
		if (chk) cout << s.substr(0, 11) << "..." << s.substr(N - 11, 11);
		else cout << s.substr(0, 9) << "......" << s.substr(N - 10, 10);
	}
}