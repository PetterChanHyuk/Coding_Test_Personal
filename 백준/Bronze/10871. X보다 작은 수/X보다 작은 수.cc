#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (X > A[i])
        {
            cout << A[i];
        }
        else
            continue;
        cout << ' ';
    }
    return 0;
}