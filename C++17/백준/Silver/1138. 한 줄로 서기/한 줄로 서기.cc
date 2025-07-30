#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	vector<int> left(N);
	for (int i = 0; i < N; i++) {
		cin >> left[i];
	}

	vector<int> result(N, 0);

	for (int i = 1; i <= N; i++) {
		int count = left[i - 1];
		for (int j = 0; j < N; j++) {
			if (result[j] == 0) { // 빈 자리
				if (count == 0) {
					result[j] = i;
					break;
				}
				count--;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}
	cout << '\n';
	return 0;
}