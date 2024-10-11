#include<iostream>
#include<string>
using namespace std;

int main() {
    string input[5];
    for (int i = 0; i < 5; i++) {
        cin >> input[i];
    }
    for (int j = 0; j < 15; j++) {
        for (int k = 0; k < 5; k++) {
            if (j < input[k].size()) {
                cout << input[k][j];
            }
        }
    }
    return 0;
}