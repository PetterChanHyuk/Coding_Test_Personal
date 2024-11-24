#include<iostream>
#include<vector>
using namespace std;

vector<bool> b(1000001);
int n, x;
int ans = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> x;
	for (int i = 0; i < n; i++) {
		if (x - a[i] > 0 && b[x - a[i]])
			ans++;
		b[a[i]] = true;
	}
	cout << ans;
}