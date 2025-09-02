#include<iostream>
#include<stack>
using namespace std;

#define X first
#define Y second

int main() {
	ios::sync_with_stdio();
	cin.tie();
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		stack<pair<int, int>> s;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			int h;
			cin >> h;
			int idx = i;
			while (!s.empty() && s.top().X >= h) {
				ans = max(ans, 1LL * (i - s.top().Y) * s.top().X);
				idx = s.top().Y;
				s.pop();
			}
			s.push({ h,idx });
		}
		while (!s.empty()) {
			ans = max(ans, 1LL * (n - s.top().Y) * s.top().X);
			s.pop();
		}
		cout << ans << '\n';
	}
}