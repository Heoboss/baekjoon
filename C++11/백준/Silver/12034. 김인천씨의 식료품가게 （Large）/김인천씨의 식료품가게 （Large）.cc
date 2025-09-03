#include <iostream>
#define fio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#include <set>
#include <vector>
int main(){
    fio;
    int T; cin >> T;
    for(int t = 1; t<= T; t++){
        int N; cin >> N;
        vector<int> cost;
        for(int i=0; i <2*N; i++){
            int tmp; cin >> tmp;
            cost.push_back(tmp);
        }

        vector<int> ans;
        for(int i=0; i<cost.size(); i++){
            int now = cost[i];
            if(now == 0) continue;
            int origin = now/3;
            origin *= 4;
            for(int j=i+1; j<cost.size(); j++){
                if(cost[j] == origin){
                    ans.push_back(now);
                    cost[j] = 0;
                    break;
                }
            }
        }
        //
        cout <<"Case #"<<t<<": ";
        for(auto i:ans){
            cout << i <<' ';
        }
        cout <<'\n';
    }
    return 0;
}