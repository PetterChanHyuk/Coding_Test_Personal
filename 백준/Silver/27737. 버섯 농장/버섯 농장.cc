#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long M;
    int K;
    cin >> N >> M >> K;
    
    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    
    // 방문 여부를 기록할 2차원 배열
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    
    // 4방향 (상, 하, 좌, 우) 이동 좌표
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    long long totalRequired = 0;   
    int totalAvailable = 0;        
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(board[i][j] == 0 && !visited[i][j]){
                int compSize = 0;
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = true;
                
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    compSize++;
                    
                    int cx = cur.first, cy = cur.second;
                    for (int d = 0; d < 4; d++){
                        int nx = cx + dx[d];
                        int ny = cy + dy[d];
                        if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                            if(board[nx][ny] == 0 && !visited[nx][ny]){
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
                totalAvailable += compSize;
                int sporesNeeded = (compSize + K - 1) / K;
                totalRequired += sporesNeeded;
            }
        }
    }
    
    if(totalAvailable == 0){
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    
    if(totalRequired <= M){
        cout << "POSSIBLE" << "\n";
        cout << M - totalRequired << "\n"; 
    } else {
        cout << "IMPOSSIBLE" << "\n";
    }
    
    return 0;
}
