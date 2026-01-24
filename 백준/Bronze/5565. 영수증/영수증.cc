#include<iostream>
using namespace std;

int main(){
    int total;
    int num;
    cin >> total;
    for(int i=0;i<9;i++){
        cin >> num;
        total = total - num;
    }
    cout << total;
}