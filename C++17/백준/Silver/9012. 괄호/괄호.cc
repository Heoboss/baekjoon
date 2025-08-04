#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string vps;
		cin >> vps;
		bool flag = false;
		stack<char> S;

		for (int i = 0; i < vps.size(); i++) {
			if (vps[i] == '(') {
				S.push(vps[i]);
			}
			else {
				if (S.empty()) {
					flag = 1;
				}
				else {
					auto tmp = S.top(); S.pop();
					if (tmp != '(') {
						flag = 1;
					}
				}
				
			}
		}
		if (S.empty() && flag != 1) {
			cout << "YES" << '\n';
		}
		else cout << "NO" << '\n';
		
	}

	return 0;
}