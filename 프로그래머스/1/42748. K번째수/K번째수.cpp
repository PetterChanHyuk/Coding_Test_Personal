#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    
    
    
    for(int i=0;i<commands.size();i++){
        int s = commands[i][0];
        int e = commands[i][1];
        int k = commands[i][2];
        
        vector<int> temp(array.begin() + (s-1), array.begin()+e);
        
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k-1]);
        temp.clear();
    }
    
    
    return answer;
}