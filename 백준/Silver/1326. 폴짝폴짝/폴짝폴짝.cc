#include<iostream>
#include<queue>
using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    
    int stone[10001];
    for (int i = 1; i <= n; i++) {
        cin >> stone[i];
    }
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0;
        return 0;
    }

    int jump[10001];
    for (int i = 1; i <= n; i++) {
        jump[i] = -1;
    }
    queue<int> Q;
    Q.push(a);
    jump[a] = 0;

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        int step = stone[cur];
        for (int next = cur + step; next <= n; next += step) {
            if (jump[next] == -1) {
                jump[next] = jump[cur] + 1;
                if (next == b) {
                    cout << jump[next];
                    return 0;
                }
                Q.push(next);
            }
        }
        for (int next = cur - step; next >= 1; next -= step) {
            if (jump[next] == -1) {
                jump[next] = jump[cur] + 1;
                if (next == b) {
                    cout << jump[next];
                    return 0;
                }
                Q.push(next);
            }
        }
    }
    cout << -1;
    return 0;
}
