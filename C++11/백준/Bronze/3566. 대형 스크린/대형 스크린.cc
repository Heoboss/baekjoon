#include <iostream>
#include <cmath>
using namespace std;

int rh, rv, sh, sv, n;

int price(int a, int b, int x, int y, int price);

// 모니터 만드는 비용 계산
int price(int a, int b, int x, int y, int price) {
    int h = max(ceil((double)rh / a), ceil((double)sh / x)); // 가로에 필요한 모니터 수
    int v = max(ceil((double)rv / b), ceil((double)sv / y)); // 세로에 필요한 모니터 수

    return h * v * price;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> rh >> rv >> sh >> sv >> n;
    
    int result = 100000000001;

    while (n--) {
        int a, b, x, y, p;
        cin >> a >> b >> x >> y >> p;

        // 모니터를 회전시킬 수 있기에
        result = min(result, min(price(a, b, x, y, p), price(b, a, y, x, p)));
    }

    cout << result << '\n';

    return 0;
}