#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int J, N;
    // 잡초의 크기 J와 문제의 수 N 입력
    cin >> J >> N;

    // cin으로 정수를 입력받은 후 버퍼에 남은 개행 문자('\n')를 제거
    // 이 과정을 생략하면 getline이 빈 줄을 읽어버리는 문제가 발생합니다.
    string buffer_flush;
    getline(cin, buffer_flush); 
    // 또는 cin.ignore(); 를 사용해도 됩니다.

    int solvable_count = 0;

    for (int i = 0; i < N; ++i) {
        string problem;
        // 공백을 포함한 한 줄 전체를 입력받음
        getline(cin, problem);

        int current_size = 0;

        // 문자열의 각 문자를 순회하며 크기 계산
        for (char c : problem) {
            if (c >= 'A' && c <= 'Z') {
                // 대문자
                current_size += 4;
            } else if (c >= 'a' && c <= 'z') {
                // 소문자
                current_size += 2;
            } else if (c >= '0' && c <= '9') {
                // 숫자
                current_size += 2;
            } else if (c == ' ') {
                // 공백
                current_size += 1;
            }
        }

        // 문제의 크기가 잡초(J)보다 작거나 같으면 풀만한 문제
        if (current_size <= J) {
            solvable_count++;
        }
    }

    // 결과 출력
    cout << solvable_count << "\n";

    return 0;
}