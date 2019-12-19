#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int a = 1, b = 1, result;
        for (int i = 2; i <= n; ++i) {
            result = a + b;
            a = b;
            b = result;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    while (cin>>n)
        cout<<s.climbStairs(n)<<endl;
    return 0;
}
