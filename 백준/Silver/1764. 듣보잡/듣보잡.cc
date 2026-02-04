#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> s1(n);
	for (int i = 0; i < n; i++) {
		cin >> s1[i];
	}
	sort(s1.begin(), s1.end());
	vector<string> answer;

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if (binary_search(s1.begin(), s1.end(), s)) {
			answer.push_back(s);
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (string s : answer) {
		cout << s << '\n';
	}
}