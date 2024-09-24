#include<iostream>
using namespace std;

int main()
{
    int A, B;
    int C;
    cin >> A >> B;
    cin >> C;
    
    B+=C;
    if(B>59)
    {
        A+=(B/60);
        B=B%60;
        if((A/24)!=0)
            A=A%24;
    }
    cout << A << " " << B;
    return 0;
}