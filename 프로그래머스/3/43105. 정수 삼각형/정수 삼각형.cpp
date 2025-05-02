#include <string>
#include <vector>

using namespace std;

vector<vector<int>> memo;

int d(int n, int x, const vector<vector<int>>& triangle){
    if(n==0) return triangle[0][0];
    
    int& ret = memo[n][x];
    if(ret!=-1)
        return ret;
    
    if(x==n) ret = triangle[n][x]+d(n-1, x-1, triangle);
    if(x==0) ret = triangle[n][x]+d(n-1, x, triangle);
    if(x<n && x>0) ret = triangle[n][x] + max(d(n-1, x-1, triangle), d(n-1, x, triangle));
    
    return ret;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n;
    n=triangle.size();
    memo.assign(n, vector<int>(n, -1));
    
    for(int i=0;i<n;i++){
        if(answer<d(n-1, i, triangle)){
            answer = d(n-1, i, triangle);
        }
    }
    
    return answer;
}