#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

string s1, s2;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s1 >> s2 >> n;
	int y1 = s1[0] - 'A'; // 킹 좌표
	int y2 = s2[0] - 'A'; // 돌 좌표
	int x1 = s1[1]-'0' -1;
	int x2 = s2[1] - '0' -1;

	x1 = 7 - x1;
	x2 = 7 - x2;

	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd.size() == 1 && cmd[0] == 'R') {
			if (y1 + 1 >= 8) continue;
			if (x1 == x2 && y2 == y1 + 1) {
				if (y2 + 1 >= 8) continue;
				y1++; y2++;
			}
			else {
				y1++;
			}
		}
		else if (cmd.size() == 1 && cmd[0] == 'L') {
			if (y1 -1 <0) continue;
			if (x1 == x2 && y2 == y1 -1) {
				if (y2 -1 < 0) continue;
				y1--; y2--;
			}
			else {
				y1--;
			}
		}
		else if (cmd.size() == 1 && cmd[0] == 'B') {
			if (x1 + 1 >=8) continue;
			if (y1 == y2 && x2 == x1 + 1) {
				if (x2 + 1 >=8) continue;
				x1++; x2++;
			}
			else {
				x1++;
			}
		}
		else if (cmd.size() == 1 && cmd[0] == 'T') {
			if (x1 - 1 <0 ) continue;
			if (y1 == y2 && x2 == x1 - 1) {
				if (x2 -1 < 0) continue;
				x1--; x2--;
			}
			else {
				x1--;
			}
		}
		else if (cmd.size() == 2 && cmd[0] == 'R' && cmd[1] == 'B') {
			if (x1 + 1 >= 8 || y1+1 >=8) continue;
			if (y1 + 1 == y2 && x2 == x1 + 1) {
				if (x2 + 1 >= 8 || y2 + 1 >=8) continue;
				x1++; x2++; y1++; y2++;
			}
			else {
				x1++; y1++;
			}
		}
		else if (cmd.size() == 2 && cmd[0] == 'R' && cmd[1] == 'T') {
			if (x1 -1 < 0 || y1 + 1 >= 8) continue;
			if (y1 + 1 == y2 && x2 == x1 - 1) {
				if (x2 - 1 <0 || y2 + 1 >= 8) continue;
				x1--; x2--; y1++; y2++;
			}
			else {
				x1--; y1++;
			}
		}
		else if (cmd.size() == 2 && cmd[0] == 'L' && cmd[1] == 'B') {
			if (y1 - 1 < 0 || x1 + 1 >= 8) continue;
			if (y1 - 1 == y2 && x2 == x1 + 1) {
				if (y2 - 1 < 0 || x2 + 1 >= 8) continue;
				x1++; x2++; y1--; y2--;
			}
			else {
				x1++; y1--;
			}
		}
		else if (cmd.size() == 2 && cmd[0] == 'L' && cmd[1] == 'T') {
			if (y1 - 1 < 0 || x1 - 1 <0) continue;
			if (y1 - 1 == y2 && x2 == x1 - 1) {
				if (y2 - 1 < 0 || x2 - 1 <0) continue;
				x1--; x2--; y1--; y2--;
			}
			else {
				x1--; y1--;
			}
		}
	}
	cout << (char)(y1 + 'A')<<(char)((8-x1)+'0') << '\n';
	cout << (char)(y2 + 'A')<<(char)((8-x2)+'0') << '\n';
	return 0;
}