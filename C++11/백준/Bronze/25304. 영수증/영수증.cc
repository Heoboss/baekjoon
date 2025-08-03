#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x,n;
	cin >> x >> n;
	int ans = 0;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		ans += a * b;
	}
	if (ans == x)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}