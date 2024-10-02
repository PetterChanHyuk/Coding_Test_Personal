#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<bool> A(31, false);
    for(int i=0;i<28;i++)
    {
        int n;
        cin >> n;
        A[n]=true;
    }
    for(int i=1;i<31;i++)
    {
        if(!A[i])
            cout << i<<endl;
    }
    return 0;
}