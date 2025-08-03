#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
using namespace std;

int n[3];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n[0] >> n[1] >> n[2];
	if (n[0] == n[1] && n[1] == n[2])
		cout << 10000 + n[0] * 1000;
	else if (n[0] == n[1])
		cout << 1000 + n[0] * 100;
	else if (n[1] == n[2])
		cout << 1000 + n[1] * 100;
	else if (n[2] == n[0])
		cout << 1000 + n[2] * 100;
	else
		cout << *max_element(n,n+3) * 100;
	return 0;
}