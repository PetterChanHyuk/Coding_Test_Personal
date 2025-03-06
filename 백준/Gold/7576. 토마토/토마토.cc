#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int board[1002][1002];
int vis[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt[1002][1002];
int check;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1) {
				q.push({ i,j });
				vis[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] < 0) continue;
			q.push({ nx,ny });
			vis[nx][ny] = 1;
			cnt[nx][ny] = cnt[cur.first][cur.second] + 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] >= 0 && vis[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}
			if (ans < cnt[i][j]) ans = cnt[i][j];
		}
	}
	cout << ans << '\n';
	return 0;
}