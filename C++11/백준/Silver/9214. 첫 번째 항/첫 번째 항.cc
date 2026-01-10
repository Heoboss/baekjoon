#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s(string str) {
	if (str.length() % 2 == 1) return str;
	string sam = "";
	for (int i = 0; i < str.length(); i += 2) {
		for (int j = 0; j < str[i] - '0'; j++) sam += str[i + 1];
	}
	if (sam == str) return sam;
	return s(sam);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int i = 1;
	string str;
	while (true) {
		cin >> str;
		if (str == "0") break;
		
		cout << "Test " << i << ": " << s(str) << endl;
		i++;
	}
}