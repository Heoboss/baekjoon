#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, w = 0;
  cin >> n;
  vector<char> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int m, k;
  cin >> m >> k;
  for (int i = 0; i < m; i++) {
    int p = 0;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      if (v[x - 1] == 'P')
        p++;
    }
    if (p == 0)
      w++;
  }
  if (w != 0)
    cout << 'W';
  else
    cout << 'P';
  return 0;
}