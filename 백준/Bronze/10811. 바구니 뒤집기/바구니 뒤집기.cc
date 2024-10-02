#include<iostream>
#include<vector>
using namespace std;

void swap(int &X, int &Y)
{
    int temp;
    temp = X;
    X = Y;
    Y = temp;
}
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N+1);
    for (int i = 1; i <= N; i++)
    {
        A[i] = i;
    }
    for (int a = 0; a < M; a++)
    {
        int i, j;
        cin >> i >> j;
        for (int b = 0; b <= (j - i)/2; b++)
        {
            swap(A[i + b], A[j - b]);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        cout << A[i]<< " ";
    }
    return 0;
}