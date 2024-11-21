#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x[4];
	for (int j = 0; j < 3; j++)
	{
		int cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			cin >> x[i];
			if (x[i] == 0)
				cnt++;
		}
		if (cnt == 0)
			cout << "E" << '\n';
		if (cnt == 1)
			cout << "A" << '\n';
		if (cnt == 2)
			cout << "B" << '\n';
		if (cnt == 3)
			cout << "C" << '\n';
		if (cnt == 4)
			cout << "D" << '\n';	
	}	
}
