#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    stack<int> s;
    vector<char> operations; // 연산 과정을 저장할 벡터
    int current_num = 1;     // 스택에 push할 오름차순 숫자

    for (int i = 0; i < n; ++i) {
        int target;
        cin >> target;

        // current_num을 target까지 push
        while (current_num <= target) {
            s.push(current_num);
            operations.push_back('+');
            current_num++;
        }

        // 스택의 top이 target과 일치하는지 확인
        if (s.top() == target) {
            s.pop();
            operations.push_back('-');
        } else {
            // 일치하지 않으면 수열을 만들 수 없음
            cout << "NO" << endl;
            return 0; // 프로그램 종료
        }
    }

    // 모든 과정을 마쳤으면 연산 출력
    for (char op : operations) {
        cout << op << '\n';
    }

    return 0;
}