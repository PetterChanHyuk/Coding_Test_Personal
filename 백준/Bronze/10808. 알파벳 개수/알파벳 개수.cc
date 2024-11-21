#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> A(26);
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		A[(int)s[i] - 97]++;
	}
	for (int e : A) {
		cout << e << " ";
	}
}