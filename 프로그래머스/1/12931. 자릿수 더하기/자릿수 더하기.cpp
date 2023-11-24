#include <iostream>
#include <cmath>

using namespace std;
int solution(int n)
{
    int answer = 0;
    for(int i=8; i>=0;i--)
    {
        if(n/pow(10,i)!=0)
        {
            answer+=n/(int)pow(10,i);
            n=n%(int)pow(10,i);
        }
    }
    return answer;
}