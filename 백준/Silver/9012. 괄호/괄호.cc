#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;
	while (n--) {
		stack<char> s;
		string str;
		bool ans = true;
		cin >> str;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') s.push(str[i]);
			else {
				if (s.empty() || s.top() != '(') {
					ans = false;
					break;
				}
				s.pop();
			}
		}
		if (!s.empty()) {
			ans = false;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}