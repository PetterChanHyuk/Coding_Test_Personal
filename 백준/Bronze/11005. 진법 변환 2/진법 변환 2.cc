#include<iostream>
#include<vector>
using namespace std;

string translate(int N, int B)
{
    if(N==0) return "0";
    
    vector<char> digits;
    while(N > 0){
        int remainder = N%B;
        if(remainder < 10)
            digits.push_back('0'+remainder);
        else
            digits.push_back('A'+(remainder-10));
        N/=B;
    }
    string output(digits.rbegin(), digits.rend());
    return output;
}
int main()
{
    int N;
    int B;
    cin >> N >> B;
    cout << translate(N, B)<<endl;
    return 0;
}