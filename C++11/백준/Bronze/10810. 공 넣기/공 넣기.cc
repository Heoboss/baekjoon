#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

vector<int> arr(101);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;
	for (int l = 0; l < m; l++) {
		int i, j, k;
		cin >> i >> j >> k;
		fill(arr.begin()+i, arr.begin()+j+1, k);
	}
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}