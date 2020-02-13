#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// math, use side length, instead of coordinates
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        for(int i = 3; i < x.size(); i++) {
            if(x[i-1]<=x[i-3] && x[i]>=x[i-2]) return true;
            if(i>3 && x[i]+x[i-4]>=x[i-2] && x[i-1]==x[i-3]) return true;
            if(i>4 && x[i-1]+x[i-5]>=x[i-3] && x[i-1]<=x[i-3] && x[i]+x[i-4]>=x[i-2] && x[i-4]<=x[i-2]) return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> x = {1,1,1,1};
    Solution s;
    x = {2, 1, 1, 2};
    x = {3, 3, 4, 2, 2};
    x = {1,1,2,2,3,1,1};
    x = {1,1,2,2,3,3,4,4,10,4,4,3,3,2,2,1,1};
    cout<<s.isSelfCrossing(x)<<endl;
    return 0;
}
