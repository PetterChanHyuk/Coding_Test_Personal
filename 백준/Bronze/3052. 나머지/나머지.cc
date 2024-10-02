#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int count=0;
    vector<int> X(42);
    for(int i=0;i<10;i++)
    {
        int A;
        cin >> A;
        X[A%42]++;
    }
    for(int i=0;i<42;i++)
    {
        if(X[i]!=0)
            count++;
    }
    cout << count;
    return 0;
}