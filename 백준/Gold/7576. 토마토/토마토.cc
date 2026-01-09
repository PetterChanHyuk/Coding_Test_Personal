#include<iostream>
#include<queue>
#include<utility>
#define X first
#define Y second
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int n, m;

int board[1002][1002];
int dist[1002][1002];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + m, -1);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) { 
				q.push({ i,j }); 
				dist[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] != 0 || dist[nx][ny] >= 0) continue;
			q.push({ nx,ny });
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			board[nx][ny] = 1;
		}
	}
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (mx < dist[i][j]) mx = dist[i][j];

		}
	}
	cout << mx;
	return 0;


}