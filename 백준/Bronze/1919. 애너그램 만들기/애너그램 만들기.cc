#include<iostream>
#include<math.h>
using namespace std;

int energram(string s1, string s2) {
	int cnt = 0;
	int a[26] = { 0, };
	int b[26] = { 0, };
	for (char c1 : s1) { a[c1 - 'a']++; }
	for (char c2 : s2) { b[c2 - 'a']++; }

	for (int i = 0; i < 26; i++)
	{
		if (a[i] != b[i])
			cnt += abs(a[i] - b[i]);
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s1;
	string s2;
	cin >> s1 >> s2;
	cout << energram(s1, s2) << '\n';
}