#include <iostream>
using namespace std;

int Arr[250000];
int N, Ans;

int main(){
    int cnt = 1;
    int i;
    cin >> N;

    for(i=0; i<N; i++){
        cin >> Arr[i];
    }

    for(i=0; i<N; i++){
        if(Arr[i] == cnt){
            cnt++;
            continue;
        }
        Ans++;
    }

    cout << Ans << "\n";

    return 0;
}