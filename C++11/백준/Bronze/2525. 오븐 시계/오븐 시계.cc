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
	int hour, min;
	int d;
	cin >> hour >> min >> d ;
	int hour_plus = (min + d) / 60;
	min = (min + d) % 60;
	hour = (hour + hour_plus) % 24;
	cout << hour << ' ' << min;
	return 0;
}