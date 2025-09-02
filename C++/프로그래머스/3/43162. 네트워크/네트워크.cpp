#include <string>
#include <vector>

using namespace std;

bool visited[200];

void dfs(int start, int n, vector<vector<int>> &computers) {
    visited[start] = true;

    // 현재 컴퓨터와 연결된 다른 컴퓨터들을 확인
    for (int i = 0; i < n; ++i) {
        // 연결되어 있고 아직 방문하지 않았다면
        if (computers[start][i] == 1 && !visited[i]) {
            // 해당 컴퓨터로 이동하여 탐색을 계속함
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            answer++;
            dfs(i, n, computers);
        }
    }
    return answer;
}