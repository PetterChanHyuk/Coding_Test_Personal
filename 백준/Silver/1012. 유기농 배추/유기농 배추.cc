#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

int board[51][51];
int vis[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt;
int main() {
	int t, m, n, k;

	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> y >> x;
			board[x][y] = 1;
		}
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0 || vis[i][j] != 0) continue;
				else {
					q.push({ i,j });
					vis[i][j] = 1;
					cnt++;
					while (!q.empty()) {
						auto cur = q.front(); q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
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
