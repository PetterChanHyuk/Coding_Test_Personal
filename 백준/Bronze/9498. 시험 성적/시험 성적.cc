#include<iostream>
using namespace std;

int main()
{
    int exam_num;
    cin >> exam_num;

    if (exam_num >= 90 && exam_num <= 100)
        cout << "A";
    else if (exam_num >= 80 && exam_num <= 89)
        cout << "B";
    else if (exam_num >= 70 && exam_num <= 79)
        cout << "C";
    else if (exam_num >= 60 && exam_num <= 69)
        cout << "D";
    else
        cout << "F";

    return 0;
}
