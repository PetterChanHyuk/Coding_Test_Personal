#include<iostream>
#include<deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	deque<pair<int, int>> dq;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num; //입력

		while (!dq.empty() && dq.back().second >= num) {
			dq.pop_back(); //덱이 안비었고 덱의 마지막의 최솟값이 num보다 크면 pop
		}

		dq.push_back({ i,num }); //입력

		if (dq.front().first <= i - m) {
			dq.pop_front();
		}

		cout << dq.front().second << ' ';
	}
	return 0;
}