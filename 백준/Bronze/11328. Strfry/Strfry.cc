#include<iostream>
using namespace std;

string strfry(string s1, string s2) {
	int a[27] = { 0, };
	int b[27] = { 0, };
	for (char c1 : s1){	a[c1 - 'a']++; }
	for (char c2 : s2){	b[c2 - 'a']++; }
	
	for (int i = 0; i < 27; i++)
	{
		if (a[i] != b[i])
			return "Impossible";
	}
	return "Possible";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string s1;
	string s2;
	for (int i = 0; i < n; i++)
	{
		cin >> s1 >> s2;
		cout << strfry(s1, s2) << '\n';
	}
}