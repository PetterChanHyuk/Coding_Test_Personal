#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<string> a(100);
	string b;
	int i = 0;
	for (i; i < 100; i++)
	{
		getline(cin, b);
		if (b.length() == 0)
			break;
		a[i] = b;
	}
	for (int j = 0; j < i; j++)
	{
		cout << a[j] << endl;
	}
	return 0;
}