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
	int t;
	cin >> t;
	int tt = 1;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << "Case #"<<tt << ": " << a << " + " << b << " = " << a + b << '\n';
		tt++;
	}
	return 0;
}