#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for(int i=0;i<N;i++)
    {
        cin >> A[i];
    }
    for(int j=0;j<N;j++)
    {
        if(A[j]<X)
            cout << A[j] << ' ';
    }
}