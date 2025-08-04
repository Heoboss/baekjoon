#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {       // EOF까지 읽기
        cout << s << '\n';          // 반드시 개행 출력
    }
    return 0;
}