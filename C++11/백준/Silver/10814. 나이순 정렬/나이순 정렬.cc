#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int n;
vector<tuple<int, int, string>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int age;
		string s;
		cin >> age >> s;
		v.push_back({ age,i,s });
	}
	sort(v.begin(), v.end());
	for (auto c : v) {
		cout << get<0>(c) << ' ' << get<2>(c) << '\n';
	}

	return 0;
}