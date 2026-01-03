#include <iostream>
using namespace std;
 
int main() {
	int a, b, n, w;
	int finds = 0;
	int idx = 0;
	cin >> a >> b >> n >> w;
    
	for (int i = 1; i < n; i++) {
		if (a * i + b * (n - i) == w) {
			idx = i;
			finds += 1;
		}
	}
    
	if (finds == 1 ) {
		cout << idx << " " << n - idx << '\n';
	}
	else {
		cout << "-1" << '\n';
	}
}