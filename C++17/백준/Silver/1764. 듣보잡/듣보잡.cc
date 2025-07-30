#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
int n, m,cnt;
vector<string> s1,s2;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	s1.resize(n);
	s2.resize(m);
	for (int i = 0; i < n; i++) {
		cin >> s1[i];
	}
	for (int i = 0; i < m; i++){ 
		cin >> s2[i];
	}
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	int aidx = 0, bidx = 0;
	vector<string> s3;
	while (1) {
		if (aidx >= n || bidx >= m) break;

		if (s1[aidx] == s2[bidx]) {
			cnt++;
			s3.push_back(s1[aidx++]);
			bidx++;
		}
		else if (s1[aidx] <= s2[bidx]) {
			aidx++;
		}
		else {
			bidx++;
		}
	}
	cout << cnt << '\n';
	for (auto c : s3) {
		cout << c << '\n';
	}
	return 0;
}