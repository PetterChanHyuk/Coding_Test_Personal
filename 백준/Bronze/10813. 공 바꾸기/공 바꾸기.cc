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
        A[i] = i + 1;
    }
    for (int a = 0; a < M; a++)
    {
        int i, j, swap;
        cin >> i >> j;
        swap = A[i - 1];
        A[i - 1] = A[j - 1];
        A[j - 1] = swap;
    }
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}