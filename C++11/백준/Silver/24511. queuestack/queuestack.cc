#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> structure_types(N);
    for (int i = 0; i < N; ++i) {
        cin >> structure_types[i];
    }

    vector<int> initial_elements(N);
    for (int i = 0; i < N; ++i) {
        cin >> initial_elements[i];
    }

    // 결과 큐를 deque로 선언
    deque<int> result_queue;

    // 큐인 구조체의 초기 원소만 뒤집어서 deque에 넣음
    for (int i = N - 1; i >= 0; --i) {
        if (structure_types[i] == 0) { // 0이 큐
            result_queue.push_back(initial_elements[i]);
        }
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; ++i) {
        int input_val;
        cin >> input_val;

        // 결과 큐의 맨 뒤에 새 원소를 넣고
        result_queue.push_back(input_val);
        
        // 맨 앞의 원소를 빼서 출력
        cout << result_queue.front() << " ";
        result_queue.pop_front();
    }
    cout << "\n";

    return 0;
}