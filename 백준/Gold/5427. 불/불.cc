#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int w, h;
        cin >> w >> h;

        string board[1002];
        static int vis1[1002][1002]; // fire time
        static int vis2[1002][1002]; // human time

        for (int i = 0; i < h; i++) cin >> board[i];

        fill(&vis1[0][0], &vis1[0][0] + 1002 * 1002, -1);
        fill(&vis2[0][0], &vis2[0][0] + 1002 * 1002, -1);

        queue<pair<int, int>> q1; // fire
        queue<pair<int, int>> q2; // human

        // init positions
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == '*') {
                    q1.push({i, j});
                    vis1[i][j] = 0;
                } else if (board[i][j] == '@') {
                    q2.push({i, j});
                    vis2[i][j] = 0;
                }
            }
        }

        // fire BFS
        while (!q1.empty()) {
            auto cur = q1.front();
            q1.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (board[nx][ny] == '#') continue;
                if (vis1[nx][ny] != -1) continue;
                vis1[nx][ny] = vis1[cur.first][cur.second] + 1;
                q1.push({nx, ny});
            }
        }

        // human BFS
        bool escaped = false;
        int ans = -1;

        while (!q2.empty() && !escaped) {
            auto cur = q2.front();
            q2.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                // escape if out of bounds
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                    escaped = true;
                    ans = vis2[cur.first][cur.second] + 1;
                    break;
                }

                if (board[nx][ny] == '#') continue;
                if (vis2[nx][ny] != -1) continue;

                int nt = vis2[cur.first][cur.second] + 1;
                // if fire arrives earlier or same time, cannot go
                if (vis1[nx][ny] != -1 && vis1[nx][ny] <= nt) continue;

                vis2[nx][ny] = nt;
                q2.push({nx, ny});
            }
        }

        if (escaped) cout << ans << '\n';
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}
