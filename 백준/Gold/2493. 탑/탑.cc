#include<iostream>
#include<stack>
#include<vector>
#include<utility>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> answer(n);
	stack<pair<int, int>> st;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
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
		cout << answer[i] << " ";
	}
	
	return 0;
}