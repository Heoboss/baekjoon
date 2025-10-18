#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 학생의 선호도를 저장할 구조체
struct Student {
    string subject;
    string fruit;
    string color;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // n명의 학생 데이터를 vector에 저장
    vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].subject >> students[i].fruit >> students[i].color;
    }

    // m개의 질의를 처리
    for (int i = 0; i < m; ++i) {
        string q_subject, q_fruit, q_color;
        cin >> q_subject >> q_fruit >> q_color;

        int match_count = 0;
        // 모든 학생의 선호도와 현재 질의를 비교
        for (int j = 0; j < n; ++j) {
            bool is_match = true;

            // 1. subject 비교 (질의가 '-'가 아닐 때만)
            if (q_subject != "-" && q_subject != students[j].subject) {
                is_match = false;
            }

            // 2. fruit 비교 (질의가 '-'가 아닐 때만)
            if (q_fruit != "-" && q_fruit != students[j].fruit) {
                is_match = false;
            }

            // 3. color 비교 (질의가 '-'가 아닐 때만)
            if (q_color != "-" && q_color != students[j].color) {
                is_match = false;
            }

            // 모든 조건이 일치하면 카운트 증가
            if (is_match) {
                match_count++;
            }
        }
        cout << match_count << "\n";
    }

    return 0;
}