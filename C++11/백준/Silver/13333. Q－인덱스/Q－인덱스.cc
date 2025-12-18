#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,k = 0, t;
    vector<int> v;
    
    cin >> n;
    
    for (int i = 0; i < n; i++){
        cin >> t;
        v.push_back(t);
    }
    
    sort(v.begin(),v.end());
    
    for(int i = 0; i < v.size(); i++){
        if(v[i] >= k && n - i >= k){
            k++;
            i--;
        }
        else if (v[i] < k && n - i < k){
            k--;
            break;
        }
        else if (v[i] < k){
            if(i == v.size()-1){
                k--;
            }
            continue;
        }
        else if (n - i < k){
            k--;
            break;
        }
    }
    cout << k;
}