#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        cout << num / 25 << ' ';
        num %= 25;
        cout << num / 10 <<' ';
        num %= 10;
        cout << num / 5 << ' ';
        num %= 5;
        cout << num << '\n';
    }


    return 0;
}
