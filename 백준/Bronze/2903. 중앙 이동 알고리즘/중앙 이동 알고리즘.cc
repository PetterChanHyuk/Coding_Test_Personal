#include<iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int count=2;
    for(int i=0;i<N;i++)
    {
        count=count*2-1;
    }
    cout << count*count<<endl;
    return 0;
}