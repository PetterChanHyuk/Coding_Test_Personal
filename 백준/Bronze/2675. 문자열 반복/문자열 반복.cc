#include<iostream>
#include<string.h>
using namespace std;


int main() {
	int T;
	int R;
	char S[21];
	cin >> T;
	for(int i=0;i<T;i++)
	{
		cin >> R >> S;

		for (int j = 0; j < strlen(S); j++)
		{
			for (int k = 0; k < R; k++)
			{
				cout << S[j];
			}
			
		}
		cout << endl;
	}

}