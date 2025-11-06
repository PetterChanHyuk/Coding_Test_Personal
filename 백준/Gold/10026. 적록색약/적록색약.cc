#include<iostream>
#include<queue>
#include<utility>
using namespace std;

string board[101];
bool vis[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int cnt1 = 0;
int cnt2 = 0;
int main(){
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	queue<pair<int, int>> q;
	
	for(int i=0;i<n;i++){
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 1||board[i][j]!='R') continue;
			q.push({ i,j });
			vis[i][j] = 1;
			cnt1++;
			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] != 'R' || vis[nx][ny]) continue;
					q.push({ nx,ny });
					vis[nx][ny] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 1 || board[i][j] != 'G') continue;
			q.push({ i,j });
			vis[i][j] = 1;
			cnt1++;
			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] != 'G' || vis[nx][ny]) continue;
					q.push({ nx,ny });
					vis[nx][ny] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 1 || board[i][j] != 'B') continue;
			q.push({ i,j });
			vis[i][j] = 1;
			cnt1++;
			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] != 'B' || vis[nx][ny]) continue;
					q.push({ nx,ny });
					vis[nx][ny] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		fill(vis[i], vis[i] + n, 0);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 1) continue;
			if (!(board[i][j] == 'R' || board[i][j] == 'G')) continue;
			q.push({ i,j });
			vis[i][j] = 1;
			cnt2++;
			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (!(board[nx][ny] == 'R' || board[nx][ny] == 'G') || vis[nx][ny]) continue;
					q.push({ nx,ny });
					vis[nx][ny] = 1;
				}
			}
		}
	}for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 1 || board[i][j] != 'B') continue;
			q.push({ i,j });
			vis[i][j] = 1;
			cnt2++;
			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] != 'B' || vis[nx][ny]) continue;
					q.push({ nx,ny });
					vis[nx][ny] = 1;
				}
			}
		}
	}
	cout << cnt1 << " " << cnt2 << '\n';
	return 0;
}