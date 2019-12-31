#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void _grayCode(vector<int> &result, int n, int cur) {
        if (n == 0) {
            result.push_back(cur);
            return;
        }
        _grayCode(result, n-1, cur);
        cur = result.back();
        _grayCode(result, n-1, cur^(1<<n-1));
    }
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        _grayCode(result, n, 0);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> vi = s.grayCode(3);
    for (int i:vi) {
        cout<<hex<<i<<endl;
    }
    return 0;
}
