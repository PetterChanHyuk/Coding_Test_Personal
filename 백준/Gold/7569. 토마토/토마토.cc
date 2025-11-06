#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int board[101][101][101];
int dist[101][101][101];

int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 1, 0, 0, 0, 0, -1 };


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n, h;
	cin >> m >> n >> h;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fill(dist[i][j], dist[i][j] + h, -1);
		}
	}

	queue<pair<pair<int, int>, int>> q;

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) { 
					q.push({ {i, j},k }); 
					dist[i][j][k] = 0;
				}
			}
		}
	}

	

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nx = cur.first.first + dx[dir];
			int ny = cur.first.second + dy[dir];
			int nz = cur.second + dz[dir];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
			if (board[nx][ny][nz] != 0 || dist[nx][ny][nz] != -1) continue;
			q.push({ {nx,ny}, nz });
			board[nx][ny][nz] = 1;
			dist[nx][ny][nz] = dist[cur.first.first][cur.first.second][cur.second] + 1;
		}
	}

	int max = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < h; k++) {
				if (board[i][j][k] == 0) {
					cout << -1 << '\n';
					return 0;
				}
				if (max < dist[i][j][k]) max = dist[i][j][k];
			}
		}
	}
	cout << max << '\n';
	return 0;

}