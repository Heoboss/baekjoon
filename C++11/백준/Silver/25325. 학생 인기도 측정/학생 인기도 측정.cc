#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int N;
map<string, int> strtoidx;
pair<int, string> pr[100];

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int idx = 0; idx < N; idx++) {
		cin >> s;
		strtoidx.insert(make_pair(s, idx));
		pr[idx].second = s;
	}

	while (cin >> s) pr[strtoidx[s]].first--;
	
	sort(pr, pr + N);

	for (int i = 0; i < N; i++) cout << pr[i].second << ' ' << -pr[i].first << '\n';
}