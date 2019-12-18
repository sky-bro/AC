#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x;
        long long m;
        for (; l <= r; ) {
            m = l + (r - l) / 2;
            if (m * m == x) return m;
            else if (m * m < x) l = m + 1;
            else r = m - 1;
        }
        return r;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int x;
    while (cin>>x) 
        cout<<s.mySqrt(x)<<endl;
    return 0;
}
