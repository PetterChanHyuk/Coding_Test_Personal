#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<string> v1(T);
    for(int i=0;i<T;i++)
    {
        cin >> v1[i];
    }
    for(int i=0;i<T;i++)
    {
        cout << v1[i].front() << v1[i].back()<<endl;
    }
    return 0;
}