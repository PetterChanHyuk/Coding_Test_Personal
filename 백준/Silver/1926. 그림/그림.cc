#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int board[501][501];
bool vis[501][501];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	queue<pair<int, int>> q;
	int draw_total = 0;
	int draw_max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) continue;
			else {
				if (vis[i][j] == 0) draw_total++;
				vis[i][j] = 1;
				q.push({ i, j });
				int cnt = 0;
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop(); cnt++;
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] || board[nx][ny] != 1) continue;
						vis[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
				if (cnt > draw_max) draw_max = cnt;
			}

		}
	}

	cout << draw_total << '\n';
	cout << draw_max << '\n';
	return 0;
}