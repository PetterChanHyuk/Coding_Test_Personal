#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int board[102][102];   // board[y][x]
bool vis[102][102];
int n, m, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k; // m: 세로(y), n: 가로(x)

    // 초기화
    for (int i = 0; i < 102; i++) {
        fill(board[i], board[i] + 102, 0);
        fill(vis[i], vis[i] + 102, false);
    }

    // 직사각형 채우기: (lx, ly) ~ (rx, ry), x는 [lx, rx), y는 [ly, ry)
    while (k--) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        for (int y = ly; y < ry; y++) {
            for (int x = lx; x < rx; x++) {
                board[y][x] = 1;
            }
        }
    }

    int cnt = 0;
    vector<int> sizes;
    queue<pair<int, int>> q;

    // BFS로 영역 개수/크기 구하기 (y: 0..m-1, x: 0..n-1)
    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (board[y][x] == 0 && !vis[y][x]) {
                cnt++;
                int area = 0;

                vis[y][x] = true;
                q.push({y, x});

                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    area++;

                    for (int dir = 0; dir < 4; dir++) {
                        int ny = cur.X + dx[dir];
                        int nx = cur.Y + dy[dir];

                        if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
                        if (board[ny][nx] != 0) continue;
                        if (vis[ny][nx]) continue;

                        vis[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }

                sizes.push_back(area);
            }
        }
    }

    sort(sizes.begin(), sizes.end());

    cout << cnt << '\n';
    for (int s : sizes) cout << s << ' ';
    cout << '\n';

    return 0;
}
