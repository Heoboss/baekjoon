#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int> pq;
int n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int comm;
		cin >> comm;
		if (comm == 0) {
			if (!pq.empty()) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
				cout << "0\n";
		}
		else {
			pq.push(comm);
		}
	}
	return 0;
}