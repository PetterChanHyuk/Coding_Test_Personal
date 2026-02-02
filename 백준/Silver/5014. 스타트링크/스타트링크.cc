#include<iostream>
#include<queue>
using namespace std;

int building[1000001];
int dx[2];
int F, S, G, U, D;
int cnt;
int main() {
	cin >> F >> S >> G >> U >> D;

	if (S == G) {
		
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= F; i++) {
		building[i] = -1;
	}

	dx[0] = U;
	dx[1] = -D;

	queue<int> q;
	q.push(S);
	building[S] = 0;

	while (!q.empty()){
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 2; dir++) {
			int nx = cur + dx[dir];
			if (nx < 1 || nx > F) continue;
			if (building[nx] != -1) continue;
			if (nx==G) {
				cnt = building[cur] + 1;
				cout << cnt;
				return 0;
			}
			q.push(nx);
			building[nx] = building[cur] + 1;
		}
	}
	cout << "use the stairs";
	return 0;
}