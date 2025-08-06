#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 110
int n, k;
deque<int> bowl[MAX];

// 오른쪽, 위 (2방향만 체크)
int dx[] = { 0, -1 };
int dy[] = { 1, 0 };

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        bowl[0].push_back(a);
    }
}

// 최댓값-최솟값이 k 이하인지 체크
bool check() {
    int mn = 1e9, mx = -1e9;
    for (auto& x : bowl[0]) {
        mn = min(mn, x);
        mx = max(mx, x);
    }
    return mx - mn <= k;
}

// 가장 적은 물고기 수 가진 어항들 모두 +1
void addFish() {
    int mn = 1e9;
    for (int i = 0; i < bowl[0].size(); i++) {
        mn = min(mn, bowl[0][i]);
    }
    for (int i = 0; i < bowl[0].size(); i++) {
        if (bowl[0][i] == mn) bowl[0][i]++;
    }
}

// width × height 블록을 공중으로 올릴 수 있는지
bool canBuild(int w, int h) {
    return (int)bowl[0].size() - w >= h;
}

// 1차 공중 회전쌓기
int buildBowl() {
    int w = 1, h = 1;
    bool turn = false; // false면 높이+1, true면 너비+1

    while (true) {
        if (!canBuild(w, h)) break;
        int tmpw = w;
        // 시계방향 회전: 왼쪽 블록을 위로 올림
        for (int i = 0; i < w; i++, tmpw--) {
            for (int j = 0; j < h; j++) {
                bowl[tmpw].push_back(bowl[j][i]);
            }
        }
        // 기존 위치 제거
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bowl[i].pop_front();
            }
        }
        if (!turn) { h++; turn = true; }
        else { w++; turn = false; }
    }
    return h;
}

// 인접조절
void adjustFish(int H) {
    deque<int> tmp[MAX];
    for (int i = 0; i < H; i++) tmp[i] = bowl[i];

    for (int i = H - 1; i >= 0; i--) {
        for (int j = 0; j < bowl[i].size(); j++) {
            for (int d = 0; d < 2; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (nx < 0) continue;
                if (ny >= bowl[i].size()) continue;
                int a = bowl[i][j], b = bowl[nx][ny];
                int diff = abs(a - b) / 5;
                if (diff > 0) {
                    if (a > b) { tmp[i][j] -= diff; tmp[nx][ny] += diff; }
                    else { tmp[nx][ny] -= diff; tmp[i][j] += diff; }
                }
            }
        }
    }
    for (int i = 0; i < H; i++) bowl[i] = tmp[i];
}

// 일렬 펼치기
void spreadBowl(int H) {
    int W = bowl[H - 1].size();
    int origin = bowl[0].size();

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            bowl[0].push_back(bowl[j][i]);
        }
    }
    for (int i = 1; i < H; i++) bowl[i].clear();
    for (int i = W; i < origin; i++) bowl[0].push_back(bowl[0][i]);
    for (int i = 0; i < origin; i++) bowl[0].pop_front();
}

// 2차 두 번 반접기
void buildBowl2() {
    int m = bowl[0].size();
    // 반 접기
    for (int i = 0; i < m / 2; i++) bowl[1].push_front(bowl[0][i]);
    for (int i = 0; i < m / 2; i++) bowl[0].pop_front();

    // 다시 반접기
    for (int i = 0; i < m / 4; i++) {
        bowl[2].push_front(bowl[1][i]);
        bowl[3].push_front(bowl[0][i]);
    }
    for (int i = 0; i < m / 4; i++) {
        bowl[0].pop_front();
        bowl[1].pop_front();
    }
}

void solution() {
    int ans = 0;
    while (true) {
        if (check()) {
            cout << ans << "\n"; break;
        }
        ans++;

        addFish();
        int H = buildBowl();
        adjustFish(H);
        spreadBowl(H);

        buildBowl2();
        adjustFish(4);
        spreadBowl(4);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solution();
    return 0;
}
