#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m, 0));
    vector<vector<int>> B(n, vector<int>(m, 0));
    vector<vector<int>> C(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }
    for (int p = 0; p < n; p++)
    {
        for (int k = 0; k < m; k++)
        {
            cin >> B[p][k];
            C[p][k] = A[p][k] + B[p][k];
        }
    }
    for (int l = 0; l < n; l++)
    {
        for (int o = 0; o < m; o++)
        {
            cout << C[l][o]<< " ";
        }
        cout << endl;
    }

}