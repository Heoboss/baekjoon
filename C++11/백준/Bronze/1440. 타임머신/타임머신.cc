#include <iostream>
#include <string>
using namespace std;

int main() {
	string time;
	getline(cin, time);
	int d[3];
	d[0] = (time.at(0) - '0') * 10 + (time.at(1) - '0');
	d[1] = (time.at(3) - '0') * 10 + (time.at(4) - '0');
	d[2] = (time.at(6) - '0') * 10 + (time.at(7) - '0');

	int hour = 0;
	int equal = 1;
	for (int i = 0; i < 3; i++) {
		if (1 <= d[i] && d[i] <= 12) hour++;//시간의 범위 안에 들어감
		if (d[i] >= 60) {//분or 초의 범위를 초과 하였으므로 시간 읽을 수 없음
			cout << 0;
			return 0;
		}
		for (int j = i+1; j < 3; j++) {
			if (d[i] == d[j]) equal++;
		}
	}
	if (hour == 0) {//범위에 안 들어가면 '시'가 없으므로 시간 읽을 수 없음
		cout << 0;
		return 0;
	}
	
	cout << hour * 2;

	return 0;
}