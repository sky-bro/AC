// standard maybe?
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0) return false;

        long result = 0;
        long y = x;
        while (x) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        if ( y == result) return true;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<boolalpha<<s.isPalindrome(-123)<<endl;
    cout<<boolalpha<<s.isPalindrome(-121)<<endl;
    cout<<boolalpha<<s.isPalindrome(121)<<endl;
    cout<<boolalpha<<s.isPalindrome(10)<<endl;
    cout<<boolalpha<<s.isPalindrome(0)<<endl;
    return 0;
}
