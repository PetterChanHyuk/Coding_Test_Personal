#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int board[102][102];
bool vis[102][102];
int cnt[102][102];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i + 1][j + 1] = s[j]-'0';
		}
	}
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	cnt[1][1] = 1;
	vis[1][1] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;
			vis[nx][ny] = 1;
			q.push({ nx, ny });
			cnt[nx][ny] = cnt[cur.first][cur.second] + 1;
		}
	}
	cout << cnt[n][m];
}