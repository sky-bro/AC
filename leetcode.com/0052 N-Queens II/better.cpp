#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int ans;
    int N;
    bool fill(int c, vector<int> &ld, vector<int> &rd, vector<int> row)
    {
        if(c==N){
            ans++;
            return true;
        }
        bool res=false;
        for(int i=0;i<N;i++)
        {
            // 左上对角，右上对角
            if(ld[i-c+N-1]!=1 && rd[i+c]!=1 && row[i]!=1)
            {
                ld[i-c+N-1]=1;
                rd[i+c]=1;
                row[i]=1;
                res=fill(c+1, ld, rd, row)||res;
                ld[i-c+N-1]=0;
                rd[i+c]=0;
                row[i]=0;
            }
        }
        return res;
    }
    int totalNQueens(int n) {
        ans=0;
        N=n;
        vector<int> ld(2*n);
        vector<int> rd(2*n);
        vector<int> row(n);
        fill(0, ld, rd, row);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.totalNQueens(4)<<endl;
    return 0;
}