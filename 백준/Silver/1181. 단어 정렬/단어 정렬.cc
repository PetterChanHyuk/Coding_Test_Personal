#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string a, string b)
{
	if (a.length() < b.length()) return 1;
	else if (a.length() > b.length()) return 0;
	else return a < b;
}

int main()
{
	int n;
	cin >> n;
	vector<string> strs(n);
	for (int i = 0; i < n; i++)
	{
		cin >> strs[i];
	}
	sort(strs.begin(), strs.end(), compare);

	for (int i = 0; i < n; i++)
	{
		if (i > 0 && strs[i] == strs[i - 1]) continue;
		cout << strs[i] << endl;
	}
	return 0;
}