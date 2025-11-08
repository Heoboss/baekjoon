#include <iostream>
#include <string>
using namespace std;

// 문자 이동 함수: 알파벳 범위에서 순환 이동
char shift(char c, int shift) {
    if ('A' <= c && c <= 'Z') { // 대문자 처리
        return 'A' + ((c - 'A' + shift + 26) % 26);
    }
    if ('a' <= c && c <= 'z') { // 소문자 처리
        return 'a' + ((c - 'a' + shift + 26) % 26);
    }
    return c; // 알파벳 외 문자 그대로 반환
}

int main() {
    int k, len;
    string s;

    cin >> k >> len;          // 밀 횟수와 문자열 길이 입력
    k = k % 26;               // 밀 횟수 최적화
    cin.ignore();             // 입력 버퍼 제거
    getline(cin, s);          // 문자열 입력

    for (char &c : s) {       // 문자열의 각 문자 처리
        c = shift(c, k);
    }

    cout << s << endl;        // 결과 출력
    return 0;
}