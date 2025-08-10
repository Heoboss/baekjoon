#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int B;
    cin >> N >> B;
    string result = ""; // B진법으로 변환된 결과를 저장할 문자열
    while (N > 0) {
        int remainder = N % B; // N을 B로 나눈 나머지를 구함
        char digit;
        // 나머지가 10보다 작으면 '0'~'9' 사이의 문자로 변환
        if (remainder < 10) {
            digit = remainder + '0'; // 예: 7 -> '7'
        }
        // 나머지가 10 이상이면 'A'~'Z' 사이의 문자로 변환
        else {
            digit = remainder - 10 + 'A'; // 예: 10 -> 'A', 11 -> 'B'
        }
        result += digit; // 계산된 문자를 결과 문자열에 추가
        N /= B;          // N을 B로 나눈 몫으로 업데이트
    }
    // 결과 문자열은 역순으로 생성되었으므로 뒤집어 줌
    reverse(result.begin(), result.end());
    cout << result << endl;
    return 0;
}