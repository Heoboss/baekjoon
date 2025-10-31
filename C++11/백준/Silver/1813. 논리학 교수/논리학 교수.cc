#include <iostream>
#include <algorithm>

using namespace std;

int num, what;
int cham[51] = {0,};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> what;
        cham[what]++;
    }
    for (int i = 50; i >= 0; i--)
    {
        if(cham[i]==i){cout<<i; return 0;}
    }
    cout << -1;
    return 0;
}