#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int a[50][50], n, m;

int isrect(int x, int y) {
	int tmp = a[x][y];
	int l = 0;
	int ret = 0;
	for (int j = y; j < m; j++) {
		if (a[x][j] == tmp && j - y > l) {
			l = j - y;
			if (x + l < n) {
				if (a[x + l][y] == tmp && a[x + l][y + l] == tmp) {
					ret = (l + 1) * (l + 1);
				}

			}
		}
	}
	return ret;
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int mx = 1;
	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < m; j++) {
			a[i][j] = row[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mx = max(mx,isrect(i, j));
		}
	}
	cout << mx;
	return 0;
}