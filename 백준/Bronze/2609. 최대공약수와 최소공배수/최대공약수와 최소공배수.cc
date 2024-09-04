#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}


int main()
{
	int a, b, result1, result2;
	cin >> a >> b;

	result1 = gcd(a, b);
	result2 = a * b / result1;
	cout << result1 << endl;
	cout << result2 << endl;

}