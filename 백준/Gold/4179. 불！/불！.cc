#include<iostream>
#include<queue>
#define X first
#define Y second
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

string board[1002];
int n, m;
int dist1[1002][1002];
int dist2[1002][1002];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for(int i=0;i<n;i++){
		cin >> board[i];
	}
	for (int i = 0; i < n; i++) {
		fill(dist1[i], dist1[i] + m, -1);
		fill(dist2[i], dist2[i] + m, -1);
	}

	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'J') { 
				q1.push({ i,j }); 
				dist1[i][j] = 0;
			}
			if (board[i][j] == 'F') {
				q2.push({ i,j });
				dist2[i][j] = 0;
			}
		}
	}
	while (!q2.empty()) {
		auto cur = q2.front(); q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#')continue;
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			q2.push({ nx,ny });
		}
	}

	while (!q1.empty()) {
		auto cur = q1.front(); q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				cout << dist1[cur.X][cur.Y] + 1 << '\n';
				return 0;
			}
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#')continue;
			if (dist2[nx][ny] != -1 && dist2[nx][ny] <= dist1[cur.X][cur.Y] + 1) continue;
			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
			q1.push({ nx,ny });
		}
	}


	cout << "IMPOSSIBLE";
	return 0;
}