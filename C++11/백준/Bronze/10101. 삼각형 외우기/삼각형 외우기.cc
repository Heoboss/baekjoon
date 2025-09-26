#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    // 1. 세 각의 합이 180인지 확인
    if (a + b + c != 180) {
        cout << "Error" << endl;
    } 
    // 2. 정삼각형 확인
    else if (a == 60 && b == 60 && c == 60) {
        cout << "Equilateral" << endl;
    } 
    // 3. 이등변삼각형 확인
    else if (a == b || b == c || a == c) {
        cout << "Isosceles" << endl;
    } 
    // 4. 부등변삼각형 확인
    else {
        cout << "Scalene" << endl;
    }

    return 0;
}