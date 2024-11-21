#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A[7];
	int total = 0;
	int tmp = 0;
	for (int i = 0; i < 7; i++)
	{
		cin >> A[i];
		if (A[i] % 2 == 1)
		{
			total += A[i];
			if (tmp == 0)
				tmp = A[i];
			if (tmp > A[i])
				tmp = A[i];
		}
	}
	if (total == 0)
		cout << -1;
	else {
		cout << total << '\n';
		cout << tmp;
	}
	
}