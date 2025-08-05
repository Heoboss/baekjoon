#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int N, K;
queue<int> q;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	cout << '<';
	while (!q.empty()) {
		for (int i = 0; i < K-1; i++) {
			q.push(q.front()); q.pop();
		}
		v.push_back(q.front()); q.pop();
	}
	for (int i = 0; i < v.size(); i++) {
		if (i == v.size() - 1) {
			cout << v[i] << '>';
		}
		else {
			cout << v[i] << ", ";
		}
	}
	return 0;
}