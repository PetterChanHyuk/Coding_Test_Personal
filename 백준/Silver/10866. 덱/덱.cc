#include<iostream>
#include<deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> dq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push_back") {
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (s == "push_front") {
			int y;
			cin >> y;
			dq.push_front(y);
		}
		else if (s == "pop_front") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (s == "size") cout << dq.size() << '\n';
		else if (s == "empty") cout << dq.empty() << '\n';
		else if (s == "front") {
			if (dq.empty()) cout << -1 << '\n';
			else cout << dq.front() << '\n';
		}
		else if (s == "back") {
			if (dq.empty()) cout << -1 << '\n';
			else cout << dq.back() << '\n';
		}
	}
}