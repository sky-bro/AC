#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.strStr("hello", "ll")<<endl;
    cout<<s.strStr("aaa", "")<<endl;
    cout<<s.strStr("aaaa", "bba")<<endl;

    return 0;
}
