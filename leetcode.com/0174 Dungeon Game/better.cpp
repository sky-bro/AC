#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        int minhealth[m][n] = {0};
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                
                if(i==m-1 && j==n-1){
                    minhealth[i][j] = max(1,1-dungeon[i][j]);
                }
                
                else if(i==m-1){
                    minhealth[i][j] = max(1,minhealth[i][j+1]-dungeon[i][j]);
                }
                
                else if(j==n-1){
                    minhealth[i][j] = max(1,minhealth[i+1][j]-dungeon[i][j]);
                }
                
                else {minhealth[i][j] = max(1,min(minhealth[i+1][j],minhealth[i][j+1])-dungeon[i][j]);}
                
            }
        }
        return minhealth[0][0];
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> dungeon = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    Solution s;
    cout<<s.calculateMinimumHP(dungeon)<<endl;
    return 0;
}
