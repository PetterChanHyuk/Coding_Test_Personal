#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N, V, count=0;
    cin >> N;
    vector<int> Array(N);
    for(int i=0;i<N;i++)
    {
        cin >> Array[i];
    }
    cin >> V;
    for(int i=0;i<N;i++)
    {
        if(V==Array[i])
            count++;
    }
    cout << count;
    return 0;
}