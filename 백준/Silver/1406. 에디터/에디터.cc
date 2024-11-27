#include<iostream>
#include<string>
#include<list>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	list<char> data;
	list<char>::iterator it = data.end();

	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		data.push_back(s[i]);
	}

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char a;
		cin >> a;
		if (a == 'L') {
			if (it != data.begin()) {
				--it;
			}
		}
		if (a == 'D') {
			if (it != data.end()) {
				++it;
			}
		}
		if (a == 'B') {
			if (it != data.begin()) {
				--it;
				it = data.erase(it);
			}
		}
		if (a == 'P') {
			char b;
			cin >> b;
			data.insert(it, b);
		}
	}

	for (auto i : data) {
		cout << i;
	}
}