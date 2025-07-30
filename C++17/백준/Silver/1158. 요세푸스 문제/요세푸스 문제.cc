#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	list<int> arr;
	
	for (int i = 0; i < n; i++)
	{
		arr.push_back(i+1);
	}
	list<int>::iterator cur = arr.begin();
	cout << '<';
	while (!arr.empty())
	{
		for (int i = 0; i < k-1; i++)
		{
			if (cur == arr.end())
			{
				cur = arr.begin();
				cur++;
			}
			else cur++;
		}
		if (cur == arr.end()) cur = arr.begin();

		if (arr.size() == 1)
		{
			cur = arr.begin();
			cout << *cur;
		}
		else
		{
			cout << *cur << ", ";
		}
			
		cur = arr.erase(cur);
		if (arr.empty() != 1)
		{
			if (cur == arr.end())
			{
				cur = arr.begin();
				//cur++;
			}	
		}
	}
	cout << '>';
	return 0;
}