#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector <int> A(5);
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> A[i];
		total += A[i];
	}
	sort(A.begin(), A.end());

	cout << total / 5 << '\n' << A[2];
	
}