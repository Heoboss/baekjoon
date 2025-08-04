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
	for (int i = 0; i <= n; i++) {
		arr[i] = i;
	}

	for (int l = 0; l < m; l++) {
		int i, j;
		cin >> i >> j;
		swap(arr[i], arr[j]);
	}

	for (int i = 1; i <= n; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}