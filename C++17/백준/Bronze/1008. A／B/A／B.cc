#include <iostream>
using namespace std;

int a, b;
double c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    c = (double)a / b;  // 강제 형 변환
    cout.precision(10);  // 소수점 10자리까지 출력
    cout << fixed << c;  // 고정 소수점 표기
}
