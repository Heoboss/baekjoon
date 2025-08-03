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
	int a, b;
	cin >> a >> b;
	int num_1 = b % 10;
	int num_10 = ((b % 100)/10);
	int num_100 = (b /100);
	cout << a*num_1 << '\n';
	cout << a*num_10 << '\n';
	cout << a*num_100 << '\n';
	cout << a*b << '\n';

	return 0;
}