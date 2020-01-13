#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cur_c = a | b;
        int result = 0;
        while (cur_c != c) {
            if ((cur_c & 1) != (c & 1)) {
                if (cur_c & 1) {
                    result += ((a & 1 )&& (b & 1)) ? 2 : 1;
                } else {
                    ++result;
                }
            }
            a>>=1; b>>=1; c>>=1; cur_c>>=1;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.minFlips(2, 6, 5)<<endl;
    return 0;
}
