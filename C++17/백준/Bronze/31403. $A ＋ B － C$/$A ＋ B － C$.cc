#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a, b, c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> c;
	cout << a + b - c << '\n';
	if (b >= 1000) cout << a * 10000 + b - c;
	else if(b>=100) cout << a * 1000 + b - c;
	else if(b>=10) cout << a * 100 + b - c;
	else cout << a * 10 + b - c;

	return 0;
}