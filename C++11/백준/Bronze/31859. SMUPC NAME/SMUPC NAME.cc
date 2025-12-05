#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n;
	string s, result = "";
	bool alpha[26] = { false, };
	cin >> n >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (!alpha[s[i] - 'a'])
		{
			result += s[i];
			alpha[s[i] - 'a'] = true;
		}
	}

	result += to_string(s.length() - result.length() + 4);
	result = to_string(n + 1906) + result;
	reverse(result.begin(), result.end());
	result = "smupc_" + result;
	cout << result;
	return 0;
}