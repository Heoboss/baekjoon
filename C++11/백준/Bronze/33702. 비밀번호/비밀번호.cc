#include <iostream>
#include <vector>

using namespace std;

// 1~9번 노드의 인접 리스트
vector<int> adj[10];
// 방문 여부를 체크할 배열
bool visited[10];

/**
 * @param current 현재 방문 중인 노드
 * @param count   지금까지 방문한 노드의 총 개수
 * @return current에서 시작하여 만들 수 있는 남은 경로의 수
 */
int dfs(int current, int count) {
    // 1. Base Case: 9개의 노드를 모두 방문했다면
    if (count == 9) {
        return 1; // 1개의 유효한 경로를 찾음
    }

    int total_paths = 0;

    // 2. Recursive Step: 현재 노드와 인접한 노드들을 탐색
    for (int neighbor : adj[current]) {
        // 아직 방문하지 않은 이웃이라면
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            total_paths += dfs(neighbor, count + 1);
            
            // 3. Backtracking: 탐색이 끝나면 방문 표시를 해제하여
            //    다른 경로가 이 노드를 사용할 수 있도록 함
            visited[neighbor] = false;
        }
    }
    return total_paths;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    // 1. 키패드(그래프)의 인접 리스트 생성
    adj[1].push_back(2); adj[1].push_back(4);
    adj[2].push_back(1); adj[2].push_back(3); adj[2].push_back(5);
    adj[3].push_back(2); adj[3].push_back(6);
    adj[4].push_back(1); adj[4].push_back(5); adj[4].push_back(7);
    adj[5].push_back(2); adj[5].push_back(4); adj[5].push_back(6); adj[5].push_back(8);
    adj[6].push_back(3); adj[6].push_back(5); adj[6].push_back(9);
    adj[7].push_back(4); adj[7].push_back(8);
    adj[8].push_back(5); adj[8].push_back(7); adj[8].push_back(9);
    adj[9].push_back(6); adj[9].push_back(8);

    // 2. "흰색" 칸(2, 4, 6, 8)에서 시작하면 불가능
    if (k == 2 || k == 4 || k == 6 || k == 8) {
        cout << 0 << endl;
        return 0;
    }

    // 3. "검은색" 칸에서 시작하는 경우 DFS 실행
    visited[k] = true;
    cout << dfs(k, 1) << endl; // k에서 시작, 현재 1개 방문

    return 0;
}