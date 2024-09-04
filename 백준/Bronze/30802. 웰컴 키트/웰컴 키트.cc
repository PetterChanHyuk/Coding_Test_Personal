#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N, S, M, L, XL, XXL, XXXL, T, P;
	cin >> N;
	cin >> S >> M >> L >> XL >> XXL >> XXXL;
	cin >> T >> P;

	cout << (int)ceil((double)S / T) + (int)ceil((double)M / T) + (int)ceil((double)L / T) + (int)ceil((double)XL / T) + (int)ceil((double)XXL / T) + (int)ceil((double)XXXL / T) << endl;
	cout << N / P << " " << N % P << endl;

	return 0;
}