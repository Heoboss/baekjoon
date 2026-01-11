#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

int main() {
    
    int N, L, K;
    cin >> N >> L >> K;

    vector<int> r(N);
    for(int i=0; i<N; i++){
        cin >> r[i];
    }


    bool flag = true;
    int cows = 0;
    while (flag == true) {
        flag = false;
        for (int i = 0; i < r.size(); i++) {
            if (L >= r[i]) {
                L += K;
                cows++;
                r.erase(r.begin() + i);
                flag = true;
            }
        }
    }

    cout << cows << '\n';
}