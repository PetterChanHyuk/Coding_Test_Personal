#include<iostream>
using namespace std;

int main()
{
    string name[20];
    string grade[20];
    float scores[20];
    float num=0, answer = 0;
    for (int i = 0; i < 20; i++) {
        cin >> name[i] >> scores[i] >> grade[i];
        if (grade[i] == "A+") {
            num += scores[i];
            answer += scores[i] * 4.5;
        }
        else if (grade[i] == "A0") {
            num += scores[i];
            answer += scores[i] * 4.0;
        }
        else if (grade[i] == "B+") {
            num += scores[i];
            answer += scores[i] * 3.5;
        }
        else if (grade[i] == "B0") {
            num += scores[i];
            answer += scores[i] * 3.0;
        }
        else if (grade[i] == "C+") {
            num += scores[i];
            answer += scores[i] * 2.5;
        }
        else if (grade[i] == "C0") {
            num += scores[i];
            answer += scores[i] * 2.0;
        }
        else if (grade[i] == "D+") {
            num += scores[i];
            answer += scores[i] * 1.5;
        }
        else if (grade[i] == "D0") {
            num += scores[i];
            answer += scores[i] * 1.0;
        }
        else if (grade[i] == "F") {
            num += scores[i];
            answer += scores[i] * 0.0;
        }
        else if (grade[i] == "P") {
            continue;
        }
    }
    cout << answer / num;
}