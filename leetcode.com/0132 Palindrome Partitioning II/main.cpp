#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minCut(string s) {
		int n=s.size();
		vector<vector<int>> valid(n,vector<int>(n,1));
		vector<int> dp(n,n);
		for(int l=2;l<=n;l++)//bottom up,the length of the substring from 2 to n
			for(int i=0,j=i+l-1;j<n;i++,j++){
				valid[i][j]=s[i]==s[j] && valid[i+1][j-1];//the most left and most right are equal and its substring is also valid
			}
		for(int i=0;i<n;i++){//the minimum cuts from 0 to index i
			if(valid[0][i]){//best situation
				dp[i]=0;
				continue;
			}
			for(int j=0;j<i;j++){//try every possible cut
				if(valid[j+1][i]){
					dp[i]=min(dp[i],dp[j]+1);
				}
			}
		}
		return dp[n-1];
	}
};