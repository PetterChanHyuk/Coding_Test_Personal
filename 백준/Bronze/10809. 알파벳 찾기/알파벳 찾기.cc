#include<iostream>
#include<string>
using namespace std;

int main()
{
    string S;
    string x = "abcdefghijklmnopqrstuvwxyz";
    cin >> S;
    for(int i=0;i<x.length();i++)
    {
        cout << (int)S.find(x[i])<< " ";
    }
    return 0;
}