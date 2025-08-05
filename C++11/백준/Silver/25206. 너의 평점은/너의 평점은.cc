#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int n = 20;
int cnt[26];
float tot;
float tot_hak;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (n--) {
        string s;
        getline(cin, s);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9' && s[i + 1] == '.') {
                if (s[i + 4] == 'A') {
                    if (s[i + 5] == '0') {
                        tot_hak += (s[i] - '0');
                        tot += (s[i] - '0')*4.0;
                    }
                    else if (s[i + 5] == '+') {
                        tot_hak += (s[i] - '0');
                        tot += (s[i] - '0') * 4.5;
                    }
                }
                else if (s[i + 4] == 'B') {
                    if (s[i + 5] == '0') {
                        tot_hak += (s[i] - '0');
                        tot += (s[i] - '0') * 3.0;
                    }
                    else if (s[i + 5] == '+') {
                        tot_hak += (s[i] - '0');
                        tot += (s[i] - '0') * 3.5;
                    }
                }
                else if (s[i + 4] == 'C') {
                    if (s[i + 5] == '0') {
                        tot_hak += (s[i] - '0');
                        tot += (s[i] - '0') * 2.0;
                    }
                    else if (s[i + 5] == '+') {
                        tot_hak += (s[i] - '0');
                        tot += (s[i] - '0') * 2.5;
                    }
                }
                else if (s[i + 4] == 'D') {
                    if (s[i + 5] == '0') {
                        tot_hak += (s[i] - '0');
                        tot += (s[i] - '0') * 1.0;
                    }
                    else if (s[i + 5] == '+') {
                        tot_hak += (s[i] - '0');
                        tot += (s[i] - '0') * 1.5;
                    }
                }
                else if (s[i + 4] == 'F') {
                    tot_hak += (s[i] - '0');
                }
            }
        }
    }
    
    cout << tot / tot_hak;
    return 0;
}