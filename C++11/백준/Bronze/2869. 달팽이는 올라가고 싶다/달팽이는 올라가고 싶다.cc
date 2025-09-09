#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, V;
    cin >> A >> B >> V;

    // (V - B) 미터를 올라가는 데 필요한 일수를 계산
    // V-A 가 목표이지만, B를 빼는게 수식적으로 더 깔끔해짐
    // (V - B - 1)은 (V-A) + (A-B) -1 과 동일
    int days = (V - B - 1) / (A - B) + 1;
    
    cout << days << endl;

    return 0;
}