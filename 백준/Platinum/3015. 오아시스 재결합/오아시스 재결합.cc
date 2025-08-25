#include<iostream>
#include<stack>
using namespace std;
#define X first
#define Y second

int main() {
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();

	int n;
	cin >> n;
	long long ans = 0;
	stack<pair<int, int>> s;
	while (n--) {
		int h;
		cin >> h;
		int cnt = 1;
		while (!s.empty() && s.top().X <= h) {
			ans += s.top().Y;
			if (s.top().X == h) {
				cnt += s.top().Y;
			}
			s.pop();
		}
		if (!s.empty()) ans++;
		s.push({ h,cnt });
	}
	cout << ans;
}


