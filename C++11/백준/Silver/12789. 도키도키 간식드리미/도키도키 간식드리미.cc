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
stack<int> s;
queue<int> q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int idx = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (idx != cur) {
			s.push(cur);
		}
		else {
			idx++;
		}
		while (!s.empty() && s.top() == idx) {
			s.pop();
			idx++;
		}
	}
	
	if (s.empty()) cout << "Nice";
	else cout << "Sad";
	return 0;
}