#include <iostream>

using namespace std;

int main() {
	int a = 1, b = 1; // a : 분자 // b : 분모

	while (1) {
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		else 	cout << a / b << " " << a % b << " / " << b << "\n";
	}
}