#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

vector<int> arr(30);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	for (int i = 0; i < 28; i++) {
		int k;
		cin >> k;
		arr[k - 1] = 1;
	}

	for (int i = 0; i < 30; i++) {
		if (arr[i] == 0)
			cout << i+1 << '\n';
	}
	return 0;
}