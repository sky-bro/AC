#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int get_mask(int n) {
        return (1 << n) - 1;
    }
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = m;
        for (int i = 0; i < 32; ++i) {
            if (m & 1) {
                int mask = get_mask(i);
                if ((result | mask) + 1 <= n) {
                    result &= (~(mask + 1));
                } else break;
            }
            m = m >> 1;
        }
        return result;
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
