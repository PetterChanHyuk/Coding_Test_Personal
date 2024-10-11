#include<iostream>
using namespace std;

int main()
{
    int n;
    int x, y;
    int count = 0;
    cin >> n;
    int answer[101][101] = { 0, };
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        for (int j = x; j < x + 10; j++) {
            for (int k = y; k < y + 10; k++) {
                if (!answer[j][k]) {
                    answer[j][k] = 1;
                    count++;
                }
            }
        }
    }
    cout << count;
}