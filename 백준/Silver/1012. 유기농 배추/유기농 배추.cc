#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
#define X first
#define Y second

int board[51][51];
bool vis[51][51];
int n, m, k;
int T;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			board[x][y] = 1;
		}
		
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j]!=1 && board[i][j]==1) {
					q.push({ i,j });
					vis[i][j] = 1;
					cnt++;
					while (!q.empty()) {
						auto cur = q.front(); q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];

							if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
							if (board[nx][ny] != 1 || vis[nx][ny]) continue;
							q.push({ nx,ny });
							vis[nx][ny] = 1;
						}
					}
				}
			}
		}
		cout << cnt << '\n';
		for (int i = 0; i < n; i++) {
			fill(board[i], board[i] + m, 0);
			fill(vis[i], vis[i] + m, 0);
			cnt = 0;
		}
	}
	return 0;
}