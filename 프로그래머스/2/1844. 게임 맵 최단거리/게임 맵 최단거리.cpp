#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int solution(vector<vector<int> > maps)
{
    int n=maps.size();
    int m=maps[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> cnt(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    q.push({0,0});
    vis[0][0]=1;
    cnt[0][0]=1;
    while(!q.empty()){
        auto cur=q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.first+dx[dir];
            int ny=cur.second+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(vis[nx][ny]||maps[nx][ny]!=1) continue;
            vis[nx][ny]=1;
            cnt[nx][ny]=cnt[cur.first][cur.second]+1;
            q.push({nx,ny});
        }
    }
    
    int answer = cnt[n-1][m-1];
    if(cnt[n-1][m-1]==0){
        answer=-1;
    }
    return answer;
}