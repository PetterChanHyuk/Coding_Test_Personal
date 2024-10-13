#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int baseToDecimal(const string& numStr, int base) {
	int power = 0;
	int result = 0;

	for (int i = numStr.size() - 1; i >= 0; --i) {
		char c = numStr[i];
		int digit = (c >= 'A') ? (c - 'A' + 10) : (c - '0');
		result += digit * pow(base, power++);
	}
	return result;
}

int main() {
	int base;
	string numStr;
	cin >> numStr >> base;
	cout << baseToDecimal(numStr, base) << endl;
	return 0;
}