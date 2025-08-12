#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// d[n] : 2 x n 크기의 직사각형을 채우는 방법의 수
// 핵심 아이디어
// 맨 오른쪽 타일을 1x2 타일로 채우는 경우 = d[n-1]
// 맨 오른쪽 타일을 2x1 타일로 채우는 경우 = d[n-2]
// 맨 오른쪽 타일을 2x2 타일로 채우는 경우 = d[n-2]

int d[10005];
int n;
int mod = 10007;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2]*2) % mod;
	}
	cout << d[n];
	return 0;
}