#include <iostream>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        char *end;
        const char *begin = s.c_str();
        for (; isspace(*begin); ++begin);
        if (!*begin) return false;
        strtof(begin, &end);
        for (; isspace(*end); ++end);
        return !*end;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    char str[50];
    while (cin>>str)
        cout<<boolalpha<<s.isNumber(str)<<endl;
    return 0;
}
