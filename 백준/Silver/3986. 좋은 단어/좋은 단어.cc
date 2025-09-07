#include<iostream>
#include<stack>
using namespace std;

int main() {
	int n;
	cin >> n;

	
	int cnt = 0;
	while (n--) {
		stack<char> s;
		string st;
		cin >> st;

		for (int i = 0; i < st.size(); i++) {
			if (!s.empty() && s.top() == st[i]) {
				s.pop();
				continue;
			}
			else {
				s.push(st[i]);
			}
		}
		if (s.empty()) cnt++;
	}

	cout << cnt;
}