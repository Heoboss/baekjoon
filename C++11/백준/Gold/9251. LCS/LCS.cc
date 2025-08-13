#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// d[i][j] : s1의 첫 i글자와 s2의 첫 j글자 사이의 LCS 길이

int d[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s1, s2;
	cin >> s1 >> s2;

	int len1 = s1.length();
	int len2 = s2.length();

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			// Case 1: 현재 위치의 문자들이 서로 같은 경우
			if (s1[i - 1] == s2[j - 1]) {
				// 이 두 문자를 제외한 LCS 길이에 1 더한다
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			// Case 2: 현재 위치의 문자들이 서로 다른 경우
			else {
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			}
		}
	}

	cout << d[len1][len2];
	return 0;
}