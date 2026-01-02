#include<iostream>
#include<utility>
#include<stack>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<pair<int, int>> st;
	vector<int> v(n);
	vector<int> answer(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i< n; i++) {
		while (!st.empty() && st.top().second < v[i]) {
			st.pop();
		}
		if (st.empty()) {
			answer[i] = 0;
		}
		else {
			answer[i] = st.top().first + 1;
		}

		st.push({ i, v[i] });
	}
	for (int i = 0; i < n; i++) {
		cout << answer[i] << ' ';
	}
	return 0;
}