#include<iostream>
#include<string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string num;
	int cnt[10] = { 0, };
	getline(cin, num);
	for (int i = 0; i < num.size(); i++)
	{
		cnt[num[i] - '0']++;
	}
	int sixnine = (cnt[6] + cnt[9])/2+(cnt[6] + cnt[9])%2;
	cnt[6] = sixnine;
	cnt[9] = sixnine;
	int tmp = 0;
	for (int i = 0; i < 10; i++)
	{
		if (tmp < cnt[i])
		{
			tmp = cnt[i];
		}
	}
	cout << tmp;
}