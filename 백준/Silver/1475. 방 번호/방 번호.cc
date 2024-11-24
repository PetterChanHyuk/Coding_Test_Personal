#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string num;
	int cnt[10] = { 0, };
	cin >> num;
	for (int i = 0; i < num.size(); i++)
	{
		cnt[num[i] - '0']++;
	}
	int sixnine = (cnt[6] + cnt[9] + 1) / 2;
	cnt[6] = sixnine;
	cnt[9] = sixnine;
	cout << *max_element(cnt, cnt + 9);
}