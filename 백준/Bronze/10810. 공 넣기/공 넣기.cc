#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        A[i] = 0;
    }
    for (int a = 0; a < M; a++)
    {
        int i, j, k;
        cin >> i >> j >> k;
        for (int b = i - 1; b < j; b++)
        {
            A[b] = k;
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}