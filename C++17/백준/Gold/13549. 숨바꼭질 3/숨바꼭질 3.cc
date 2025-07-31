#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, K;
int board[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    memset(board, -1, sizeof(board));

    queue<int> q;
    q.push(N);
    board[N] = 0;

    while(!q.empty()) {
        int cur = q.front(); q.pop();

        int nx = cur * 2;
        if (nx < 100001 && (board[nx] == -1 || board[nx] > board[cur])) {
            board[nx] = board[cur];
            q.push(nx); 
        }

        nx = cur - 1;
        if (nx >= 0 && (board[nx] == -1 || board[nx] > board[cur] + 1)) {
            board[nx] = board[cur] + 1;
            q.push(nx);
        }

        nx = cur + 1;
        if (nx < 100001 && (board[nx] == -1 || board[nx] > board[cur] + 1)) {
            board[nx] = board[cur] + 1;
            q.push(nx);
        }
    }

    cout << board[K];
    return 0;
}