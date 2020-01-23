#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n, int res = 0) {
        for (int p = 1 << 30; p >= max(1, n - m); p >>= 1)
            if ((m & p) && (n & p))
                res += p;
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int m, n;
    while (cin>>m>>n)
        cout<<s.rangeBitwiseAnd(m, n)<<endl;
    return 0;
}
