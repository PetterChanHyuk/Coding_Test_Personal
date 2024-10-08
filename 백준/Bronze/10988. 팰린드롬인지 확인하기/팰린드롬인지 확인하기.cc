#include<iostream>
#include<string>
using namespace std;

int main()
{
    string word;
    int answer = 1;
    cin >> word;
    for (int i = 0; i < word.length() / 2; i++)
    {
        if (word[i] != word[word.length() - 1 - i]) {
            answer = 0;
            break;
        }
            
    }
    cout << answer;
    return 0;
}