#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, x2, y2, x3, y3;
    
    // 세 꼭짓점의 좌표 입력
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    int x4, y4;

    // XOR 연산을 이용해 한 번만 등장하는 x좌표 찾기
    x4 = x1 ^ x2 ^ x3;
    
    // XOR 연산을 이용해 한 번만 등장하는 y좌표 찾기
    y4 = y1 ^ y2 ^ y3;

    cout << x4 << " " << y4 << endl;

    return 0;
}