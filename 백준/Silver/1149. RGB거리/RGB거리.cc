#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    int cost[1001][3];
    for (int i = 0; i < N; i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    
    int dp[1001][3];
    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];
    
    for (int i = 1; i < N; i++){
        dp[i][0] = cost[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = cost[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = cost[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }
    
    int answer = min({ dp[N-1][0], dp[N-1][1], dp[N-1][2] });
    cout << answer << "\n";
    
    return 0;
}
