#include <iostream>
#include <cctype>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1, result = 0;
        for (; i >= 0 && s[i] == ' '; --i );
        for (; i >= 0 && s[i] != ' '; --i, ++result);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.lengthOfLastWord("hello world")<<endl;
    cout<<s.lengthOfLastWord("hello world  ")<<endl;
    cout<<s.lengthOfLastWord("  ")<<endl;
    return 0;
}
