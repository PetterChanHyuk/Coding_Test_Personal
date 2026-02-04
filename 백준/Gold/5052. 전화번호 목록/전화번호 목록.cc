#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		bool check = true;
		int n;
		cin >> n;
		vector<string> s1;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			s1.push_back(s);
		}
		sort(s1.begin(), s1.end());

		for (int i = 0; i < n-1; i++) {
			if (s1[i + 1].substr(0, s1[i].length()) == s1[i]) {
				cout << "NO" << '\n';
				check = false;
				break;
			}
		}
		if (check) {
			cout << "YES" << '\n';
		}
	}
	
}