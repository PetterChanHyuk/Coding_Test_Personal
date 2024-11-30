#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		string s;
		getline(cin, s);
		if (s == ".") break;
		stack<char> stack;
		bool answer = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') stack.push('(');
			else if (s[i] == '[') stack.push('[');
			else if (s[i] == ')') {
				if (stack.empty() || stack.top()!='(') {
					answer = false;
					break;
				}
				stack.pop();
			}
			else if (s[i] == ']') {
				if (stack.empty() || stack.top()!='[') {
					answer = false;
					break;
				}
				stack.pop();
			}
		}
		if (!stack.empty()) answer = false;
		cout << (answer ? "yes" : "no") << '\n';
	}
	return 0;
}