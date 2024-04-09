#include <iostream>
using namespace std;
#include <vector>
int main()
{
	int N;
	cin >> N;

	vector <float> score(N);
	for (int i = 0; i < N; i++)
	{
		cin >> score[i];
	}
	float M=0;

	for (int j = 0; j < N; j++)
	{
		if (M < score[j])
		{
			M = score[j];
		}
	}
	float sum = 0;
	for (int k = 0; k < N; k++)
	{
		score[k] = score[k] / M * 100;
		sum += score[k];
	}
	float average = sum / (float)N;
	cout << average;

	return 0;
}