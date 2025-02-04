#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        vector<vector<int>> grid(h, vector<int>(w, 0));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> grid[i][j];
            }
        }
        int islands = 0;
        int dx[8] = {-1, -1, -1,  0, 0, 1, 1, 1};
        int dy[8] = {-1,  0,  1, -1, 1,-1, 0, 1};
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 1) {
                    islands++;  
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 0;  
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for (int dir = 0; dir < 8; dir++) {
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];
                            if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] == 1) {
                                grid[nx][ny] = 0;  
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }   
        cout << islands << "\n";  
    }
    return 0;
}