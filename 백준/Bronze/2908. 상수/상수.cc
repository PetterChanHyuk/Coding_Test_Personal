#include<iostream>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    int temp = A%10*100;
    temp += A/10%10*10;
    temp += A/100;
    A=temp;
    temp = B%10*100;
    temp += B/10%10*10;
    temp += B/100;
    B=temp;
    if(A>B)
        cout << A;
    else
        cout << B;
    return 0;
}