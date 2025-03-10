#include<iostream>
#include<queue>
using namespace std;

int dist[100001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	fill(dist, dist + 100001, -1);
	dist[n] = 0;
	queue<int> q;
	q.push(n);
	while (dist[k]==-1) {
		int cur = q.front(); q.pop();
		for (int nx : {cur-1, cur+1, 2*cur}) {
			if (nx < 0 || nx >= 100001) continue;
			if (dist[nx] != -1) continue;
			q.push(nx);
			dist[nx] = dist[cur] + 1;
		}
	}
	cout << dist[k] << '\n';
}
