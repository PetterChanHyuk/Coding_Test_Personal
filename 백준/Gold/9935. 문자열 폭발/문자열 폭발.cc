#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s, bomb;
	cin >> s >> bomb;

	string answer;
	answer.reserve(s.size());
	int m = bomb.size();
	for (char c : s) {
		answer.push_back(c);

		if (answer.size() >= m) {
			bool same = true;
			for (int i = 0; i < m; i++) {
				if (answer[answer.size() - m + i] != bomb[i]) {
					same = false;
					break;
				}
			}
			if (same) answer.resize(answer.size() - m);
		}
	}
	if (answer.empty()) cout << "FRULA\n";
	else cout << answer << '\n';
}