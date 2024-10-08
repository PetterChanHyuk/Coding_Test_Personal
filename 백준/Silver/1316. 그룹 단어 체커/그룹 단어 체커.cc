#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N, count = 0;
    string A;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> A;
        vector<bool> alphabet(26, false);
        alphabet[(int)A[0] - 97] = true;

        for (int j = 1; j < A.size(); j++) {
            if (A[j] == A[j - 1]) {
                continue;
            }
            else if (A[j] != A[j - 1] && alphabet[(int)A[j] - 97] == true) {
                count++;
                break;
            }

            else {
                alphabet[(int)A[j] - 97] = true;
            }
        }
    }
    cout << N - count;
    return 0;
}