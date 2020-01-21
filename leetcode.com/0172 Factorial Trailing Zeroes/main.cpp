#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        long div = 5;
        int result = 0;
        while (n/div) {
            result += n/div;
            div *= 5;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.trailingZeroes(125)<<endl;
    return 0;
}
