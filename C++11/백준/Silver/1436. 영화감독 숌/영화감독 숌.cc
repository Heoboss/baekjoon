#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int num = 666;
    int count = 1;
    // N번째 종말의 숫자를 찾을 때까지 반복
    while (count != N) {
        num++; // 다음 숫자로 이동
        // 숫자를 문자열로 변환하여 "666"이 포함되어 있는지 확인
        if (to_string(num).find("666") != string::npos) {
            count++;
        }
    }
    cout << num << endl;
    return 0;
}