#include<iostream>
#include<queue>
using namespace std;

int dx[8] = { -2, -2,-1,-1,1,1,2,2 };
int dy[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };
int board[301][301];
int dist[301][301];
bool chk;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;


	while (n--) {
		chk = false;
		int size;
		cin >> size;
		
		queue<pair<int, int>> q;
		for (int i = 0; i < size; i++) {
			fill(dist[i], dist[i] + size, -1);
			fill(board[i], board[i] + size, 0);
		}

		for (int i = 0; i < 2; i++) {
			int a, b;
			cin >> a >> b;
			if (board[a][b] == 1) { 
				cout << 0 << '\n'; 
				continue;
			}
			board[a][b] = 1;
			if (q.empty()) { 
				q.push({ a,b }); 
				dist[a][b] = 0;
			}
		}

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				
				if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
				if (dist[nx][ny] != -1) continue;

				if (board[nx][ny] == 1) {
					dist[nx][ny] = dist[cur.first][cur.second] + 1;
					cout << dist[nx][ny] << '\n';
					chk = true;
					break;
				}

				q.push({ nx,ny });
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
			}
			if (chk) break;
		}

	}
}

