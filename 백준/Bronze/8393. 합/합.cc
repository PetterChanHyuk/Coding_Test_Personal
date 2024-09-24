#include<iostream>

using namespace std;
int main()
{
    int n, answer=0;
    cin >> n;
    
    for(int i=1;i<=n;i++)
    {
        answer+=i;
    }
    cout << answer;
    return 0;
}