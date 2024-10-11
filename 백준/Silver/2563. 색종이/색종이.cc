#include<iostream>
using namespace std;

int main()
{
    int n;
    int x, y;
    cin >> n;
    int answer[101][101] = {0, };
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        for (int j = x; j < x+10; j++) {
            for (int k = y; k < y+10; k++) {
                answer[j][k] = 1;
            }
        }
    }
    int count=0;
    for (int l = 0; l < 101; l++) {
        for (int m = 0; m < 101; m++) {
            if (answer[l][m] == 1) {
                count++;
            }
        }
    }
    cout << count;
}