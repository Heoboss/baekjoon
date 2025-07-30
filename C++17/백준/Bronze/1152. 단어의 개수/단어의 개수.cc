#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string str;
    getline(cin, str);  // 전체 입력 받기

    istringstream iss(str);  // 공백 기준으로 문자열을 분리하는 스트림
    string word;
    int count = 0;

    while (iss >> word) {  // 단어 하나씩 추출
        count++;
    }

    cout << count << "\n";  // 단어 개수 출력
    return 0;
}
