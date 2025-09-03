#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int cnt = 0;
	deque<int> dq;

	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;

		int idx = find(dq.begin(), dq.end(), a) - dq.begin();
		while (a != dq.front()) {
			if (idx < dq.size() - idx) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			cnt++;
		}
		dq.pop_front();
	}
	cout << cnt;
}