#include<iostream>
#include<stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	stack<char> st;
	int num = 1;
	int sum = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			num *= 2;
			st.push(s[i]);
		}
		else if (s[i] == '[') {
			num *= 3;
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			if (st.empty() || st.top() != '(') {
				cout << 0;
				return 0;
			}
			if (s[i - 1] == '(') {
				sum += num;
			}
			st.pop();
			num /= 2;
		}
		else {
			if (st.empty() || st.top() != '[') {
				cout << 0;
				return 0;
			}
			if (s[i - 1] == '[') {
				sum += num;
			}
			st.pop();
			num /= 3;
		}
	}
	if (st.empty()) cout << sum;
	else cout << 0;
}