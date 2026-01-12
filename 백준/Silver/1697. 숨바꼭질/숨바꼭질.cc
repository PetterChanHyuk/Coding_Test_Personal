#include<iostream>
#include<queue>
using namespace std;

int dist[100001];
int dx[2] = { 1, -1 };
int main(){
	int n, k;
	cin >> n >> k;
	fill(dist, dist + 100001, -1);
	dist[n] = 0;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 3; dir++) {
			int nx;
			if (dir == 2) {
				nx = cur * 2;
			}
			else {
				nx = cur + dx[dir];
			}
			if (nx < 0 || nx >= 100001) continue;
			if (dist[nx] != -1) continue;
			q.push(nx);
			dist[nx] = dist[cur] + 1;
		}
	}
	cout << dist[k] << '\n';
}
