#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> A(9);
	int total = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> A[i];
		total += A[i];
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i == j) continue;
			else
			{
				int tmp = total - A[i] - A[j];
				if (tmp == 100)
				{
					if (i > j)
					{
						A.erase(A.begin() + i);
						A.erase(A.begin() + j);
						break;
					}
					else
					{
						A.erase(A.begin() + j);
						A.erase(A.begin() + i);
						break;
					}
					
				}
			}
		}
		if (A.size() == 7)
			break;
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < 7; i++)
		cout << A[i] << '\n';
}