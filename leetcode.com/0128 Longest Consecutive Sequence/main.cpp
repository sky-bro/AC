#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int,int> m;
		for(auto x:nums){
			if(m.count(x)) continue;
			auto it_l=m.find(x-1);
			auto it_r=m.find(x+1);
			int l=it_l==m.end() ? 0:it_l->second;
			int r=it_r==m.end() ? 0:it_r->second;
            // 只需要修改sequence边界的值
			if(l>0 && r==0){
				m[x-l]=l+1;
				m[x]=l+1;
			}
			else if(r>0 && l==0){
				m[x+r]=r+1;
				m[x]=r+1;
			}
			else if(r>0 && l>0){
                // 这里的m[x]可以任意赋值，只要让m.count(x)为真就行
				m[x]=l+r+1;
				m[x+r]=l+r+1;
				m[x-l]=l+r+1;
			}
			else{
				m[x]=1;
			}
		}
		int res=0;
		for(auto x:m){
			res=max(res,x.second);
		}

		return res;

	}
};