#include<iostream>
using namespace std;

int main()
{
    int num_1, num_2, num_3, num_4, num_5, num_6;
    cin >> num_1>>num_2;
    num_3=num_1*(num_2%10);
    cout<<num_3<<endl;
    num_4=num_1*((num_2%100)-(num_2%10))/10;
    cout<<num_4<<endl;
    num_5=num_1*(num_2/100);
    cout<<num_5<<endl;
    num_6=num_3+num_4*10+num_5*100;
    cout<<num_6;
    return 0;
}