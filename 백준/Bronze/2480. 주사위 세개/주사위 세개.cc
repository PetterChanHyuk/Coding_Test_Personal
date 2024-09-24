#include<iostream>
using namespace std;

int main()
{
    int d_1, d_2, d_3;
    cin >> d_1 >> d_2 >> d_3;
    
    if((d_1==d_2)&&(d_2==d_3))
        cout << 10000+(d_1*1000);
    else if((d_1==d_2)&&(d_1!=d_3))
        cout << 1000+(d_1*100);
    else if((d_1==d_3)&&(d_1!=d_2))
        cout << 1000+(d_1*100);
    else if((d_3==d_2)&&(d_1!=d_3))
        cout << 1000+(d_2*100);
    else if((d_1!=d_2) && (d_2!=d_3) && (d_3!=d_1)){
        if((d_1>d_2) && (d_1>d_3))
            cout << d_1*100;
        else if((d_2>d_1) && (d_2>d_3))
            cout << d_2*100;
        else if((d_3>d_1) && (d_3>d_2))
            cout << d_3*100;
    }
    return 0;
}