#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res=0;
        int x;
        int n=matrix.size();
        if (n==0) return 0;
        int m=matrix[0].size();
        if (m==0) return 0;
        vector<int> mat(m, 0);
        for (int i=0; i<m; ++i){
            mat[i]=matrix[0][i]-48;
            if (mat[i]==1) res=1;
        }
        int prev;
        for (int i=1; i<n; ++i){
            prev=mat[0];
            if (prev>res) res=prev;
            mat[0]=matrix[i][0]-48;
            for (int j=1; j<m; ++j){
                if (matrix[i][j]!='0'){
                    x=min(mat[j-1], min(prev, mat[j]))+1;
                    if (x>res){
                        res=x;
                    }
                    prev=mat[j];
                    mat[j]=x;
                }
                else{
                    prev=mat[j];
                    mat[j]=0;
                }
            };
        };
        return res*res;
    }
};