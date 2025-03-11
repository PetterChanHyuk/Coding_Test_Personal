#include<iostream>
#include<queue>
#include<utility>
// #include<algorithm>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt;
int total1;
int total2;
string board[101];
int vis[101][101];
char color[3]{ 'R', 'G', 'B' };


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {

		cin >> board[i];
	}
	queue<pair<int, int>> q;
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == color[k]&&vis[i][j]!=1) {
					vis[i][j] = 1;
					q.push({ i,j });
					while (!q.empty()) {
						auto cur = q.front(); q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
							if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (board[nx][ny] != color[k] || vis[nx][ny]) continue;
							q.push({ nx,ny });
							vis[nx][ny] = 1;
						}
					}
					cnt++;
				}
			}
		}
	}
	total1 = cnt;
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vis[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'R') {
				board[i][j] = 'G';
			}
		}
	}
	for (int k = 1; k < 3; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == color[k] && vis[i][j] != 1) {
					vis[i][j] = 1;
					q.push({ i,j });
					while (!q.empty()) {
						auto cur = q.front(); q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
							if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (board[nx][ny] != color[k] || vis[nx][ny]) continue;
							q.push({ nx,ny });
							vis[nx][ny] = 1;
						}
					}
					cnt++;
				}
			}
		}
	}
	total2 = cnt;

	cout << total1 << " " << total2 << '\n';
	return 0;
}