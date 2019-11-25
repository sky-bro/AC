#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        char buf[0x10];
        sprintf(buf, "%d", x);
        // cout<<x<<endl;
        // cout<<buf<<endl;
        int len = strlen(buf);
        for (int i = 0, j = len-1; i<j; ++i, --j){
            if (buf[i] != buf[j]) return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<boolalpha<<s.isPalindrome(-123)<<endl;
    cout<<boolalpha<<s.isPalindrome(-121)<<endl;
    cout<<boolalpha<<s.isPalindrome(121)<<endl;
    cout<<boolalpha<<s.isPalindrome(10)<<endl;
    return 0;
}
