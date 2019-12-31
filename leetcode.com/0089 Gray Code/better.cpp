#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < pow(2,n); ++i) {
            res.push_back((i >> 1) ^ i);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    const int n = 3;
    vector<int> vi = s.grayCode(n);
    for (int i:vi) {
        cout<<bitset<n>(i)<<endl;
    }
    return 0;
}
