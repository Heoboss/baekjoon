#include <string>
#include <vector>
using namespace std;

int answer = 0;

// index: 현재 사용할 숫자의 인덱스
// sum: 현재까지의 합계
void dfs(vector<int> &numbers, int target, int index, int sum) {
    // 탈출 조건: 모든 숫자를 다 사용했을 경우
    if (index == numbers.size()) {
        // 2. 목표 값과 합계가 같은지 확인
        if (sum == target) {
            answer++;
        }
        return;
    }

    // 다음 숫자를 더하거나 빼는 두 가지 경우를 모두 탐색
    dfs(numbers, target, index + 1, sum + numbers[index]);
    dfs(numbers, target, index + 1, sum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    // DFS 시작: 0번째 인덱스부터, 초기 합계 0으로 시작
    dfs(numbers, target, 0, 0);
    return answer;
}