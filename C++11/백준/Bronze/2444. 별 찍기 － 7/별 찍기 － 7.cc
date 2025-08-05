#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int max_num = 2 * n - 1;
    int space = n - 1;
    int star = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < space; j++) {
            cout << ' ';
        }
        for (int k = 0; k < star; k++) {
            cout << '*';
        }
        cout << '\n';
        star += 2;
        space -= 1;
    }
    star -= 4;
    space += 2;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < space; j++) {
            cout << ' ';
        }
        for (int k = 0; k < star; k++) {
            cout << '*';
        }
        cout << '\n';
        star -= 2;
        space += 1;
    }
    return 0;
}