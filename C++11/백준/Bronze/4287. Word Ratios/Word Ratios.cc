#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b, c;
    while (cin >> a && a != "#") {
        cin >> b >> c;

        string d = ""; // 결과를 저장할 네 번째 단어

        for (size_t i = 0; i < a.length(); ++i) {
            // 1. A -> B 이동 칸 수 계산
            int shift = (b[i] - a[i] + 26) % 26;

            // 2. C에 동일한 이동을 적용하여 D의 문자를 계산
            char decoded_char = ((c[i] - 'a') + shift) % 26 + 'a';
            d += decoded_char;
        }
        
        cout << a << " " << b << " " << c << " " << d << "\n";
    }

    return 0;
}