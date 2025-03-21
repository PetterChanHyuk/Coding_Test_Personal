#include<iostream>
using namespace std;

int cnt;

void d(int n) {
	if (n == 0) { cnt++; }
	if (n - 1 >= 0) d(n - 1);
	if (n - 2 >= 0) d(n - 2);
	if (n - 3 >= 0) d(n - 3);
}

int main() {
	int n;
	int test;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> n;
		d(n);
		cout << cnt << '\n';
		cnt = 0;
	}
}