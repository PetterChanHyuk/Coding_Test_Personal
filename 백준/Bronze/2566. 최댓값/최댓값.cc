#include<iostream>
using namespace std;

int main()
{
    int x[9][9];
    int max = 0;
    int rows = 0, columns = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> x[i][j];
            if (x[i][j] > max)
            {
                max = x[i][j];
                rows = i;
                columns = j;
            }
        }
    }
    cout << max << endl;
    cout << rows+1 << " " << columns+1;
}