#include<iostream>
#include<string>
using namespace std;

int main()
{
    string x;
    cin >> x;
    int count = 0;
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] >= 'A' && x[i] <= 'C')
            count += 3;
        else if (x[i] >= 'D' && x[i] <= 'F')
            count += 4;
        else if (x[i] >= 'G' && x[i] <= 'I')
            count += 5;
        else if (x[i] >= 'J' && x[i] <= 'L')
            count += 6;
        else if (x[i] >= 'M' && x[i] <= 'O')
            count += 7;
        else if (x[i] >= 'P' && x[i] <= 'S')
            count += 8;
        else if (x[i] >= 'T' && x[i] <= 'V')
            count += 9;
        else if (x[i] >= 'W' && x[i] <= 'Z')
            count += 10;
    }
    cout << count;
}