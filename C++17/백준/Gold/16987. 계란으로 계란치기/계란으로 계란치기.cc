#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 계란은 내구도와 무게
// 내구도 0 이하 계란 깨짐
// 상대 계란의 무게만큼 내구도 깎임

int N,ans;
int durability,weight;
vector<pair<int,int>> eggs;
bool is_broken[8];


void func(int k, int num) {
    if (k == N) {
        ans = max(ans, num);
        return;
    }

    if (is_broken[k]) {
        func(k+1, num);
        return;
    }

    bool hit = false;
    for (int i = 0; i < N; i++) {
        if (i == k || is_broken[i]) continue;
        if (is_broken[k]) continue;

        hit = true;

        int d1 = eggs[k].first, d2 = eggs[i].first;
        eggs[k].first -= eggs[i].second;
        eggs[i].first -= eggs[k].second;

        bool broken_k = false, broken_i = false;
        int add = 0;
        if (eggs[k].first <= 0 && !is_broken[k]) {
            is_broken[k] = true; broken_k = true; add++;
        }
        if (eggs[i].first <= 0 && !is_broken[i]) {
            is_broken[i] = true; broken_i = true; add++;
        }

        func(k+1, num + add);

        // 복구
        eggs[k].first = d1; eggs[i].first = d2;
        if (broken_k) is_broken[k] = false;
        if (broken_i) is_broken[i] = false;
    }

    if (!hit) func(k+1, num);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    eggs.resize(N+1);
    for(int i = 0 ;i < N; i++){
        cin >> durability >> weight;
        eggs[i] = {durability, weight};
    }

    func(0,0);
    cout << ans;
    return 0;
}