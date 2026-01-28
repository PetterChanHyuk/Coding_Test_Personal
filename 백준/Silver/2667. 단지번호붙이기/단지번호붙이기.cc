#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>
#define X first
#define Y second
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

string board[26];
bool vis[26][26];
int apt_num = 0;
int part_apt_num = 0;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> board[i];
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < t; i++) {
		fill(vis[i], vis[i] + t, false);
	}
	
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			if (board[i][j] == '0'||vis[i][j]) continue;
			q.push({ i,j });
			vis[i][j] = true;
			apt_num = apt_num + 1;
			part_apt_num = 0;
			while (!q.empty()) {
				auto cur = q.front(); q.pop(); part_apt_num++;
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= t || ny < 0 || ny >= t) continue;
					if (board[nx][ny] == '0' || vis[nx][ny]) continue;
					q.push({ nx,ny });
					vis[nx][ny] = true;
				}
			}
			v.push_back(part_apt_num);
		}
	}
	sort(v.begin(), v.end());
	cout << apt_num << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}