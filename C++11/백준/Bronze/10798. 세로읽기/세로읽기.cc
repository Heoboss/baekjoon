#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector<string> s(5);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 5;
	int mxs = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		mxs = max(mxs,  int(s[i].size()));
	}
	for (int i = 0; i < mxs; i++) {
		if (i < int(s[0].size())) {
			cout << s[0][i];
		}
		if (i < int(s[1].size())) {
			cout << s[1][i];
		}
		if (i < int(s[2].size())) {
			cout << s[2][i];
		}
		if (i < int(s[3].size())) {
			cout << s[3][i];
		}
		if (i < int(s[4].size())) {
			cout << s[4][i];
		}
	}
		
	return 0;
}