#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <list>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<int> q;
	int N;
	cin >> N;
	for (int i = 1; i < N+1; i++)
	{
		q.push(i);
	}
	int input = 0;
	while (q.size() > 2) 
	{
		q.pop();
		input = q.front();
		q.pop();
		q.push(input);
	}
	if (q.size() == 1) cout << q.front();
	else
	{
		cout << q.back();
	}
	return 0;
}