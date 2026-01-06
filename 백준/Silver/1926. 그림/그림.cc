#include<iostream>
#include<queue>
#include<utility>

#define X first
#define Y second


int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int board[502][502];
bool vis[502][502];

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n, m;
	int cnt = 0;
	int max = 0;
	int num = 0;
	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 1 || vis[i][j]) continue;
			else {
				if (vis[i][j] == 0) num++;
				q.push({ i,j });
				vis[i][j] = 1;
				cnt = 0;

				while (!q.empty()) {
					auto cur = q.front(); q.pop(); cnt++;
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] != 1 || vis[nx][ny]) continue;
						q.push({ nx,ny });
						vis[nx][ny] = 1;
					}
				}
				if (max < cnt) max = cnt;
			}
		}
	}
	cout << num << '\n';
	cout << max << '\n';
	return 0;
}
