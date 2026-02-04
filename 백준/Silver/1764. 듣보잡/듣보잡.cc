#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	unordered_set<string> s1;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		
		s1.insert(s);
	}
	vector<string> answer;
	
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (s1.find(s) != s1.end()) {
			answer.push_back(s);
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	for (string str : answer) {
		cout << str << '\n';
	}
	
	return 0;
}