#include <iostream>

using namespace std;

int factorial(int x)
{
	if (x == 0)
		return 1;
	return x * factorial(x - 1);
}

int BC(int n, int k)
{
	return factorial(n)/(factorial(n-k)*factorial(k));
}



int main()
{
	int N, K;
	cin >> N >> K;

	cout << BC(N, K);



}