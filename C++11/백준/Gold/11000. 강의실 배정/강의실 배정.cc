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
	
	int n;
	cin >> n;

	vector<pair<int, int>> lectures(n);
	for (int i = 0; i < n ; i++) {
		cin >> lectures[i].first >> lectures[i].second;
	}
	
	sort(lectures.begin(), lectures.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(lectures[0].second);

	for (int i = 1; i < n; i++) {
		if (pq.top() <= lectures[i].first) {
			pq.pop();
		}
		pq.push(lectures[i].second);
	}

	cout << pq.size();
	return 0;
}
