#include<iostream>
#include<stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	int total = 0;
	cin >> k;
	stack<int> s;
	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			if (s.empty()) {
				continue;
			}
			else { 
				total -= s.top();
				s.pop(); 
			}
		}
		else {
			s.push(num);
			total += num;
		}
	}
	cout << total;
}