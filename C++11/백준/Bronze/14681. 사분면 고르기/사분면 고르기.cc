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


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, y;
	cin >> x >> y ;
	if (x > 0 && y > 0)
		cout << 1;
	else if (x < 0 && y > 0)
		cout << 2;
	else if (x < 0 && y < 0)
		cout << 3;
	else
		cout << 4;
	return 0;
}