#include <iostream>
#include <regex>

using namespace std;

regex r(R"(^(\s*)?[-\+]?(((\d{1,})(\.\d{1,})?)|(\d{1,}\.)|(\.\d{1,}))(e[-\+]?\d{1,})?(\s*)?$)");
class Solution {
public:
    bool isNumber(const string& s) {
        return regex_match(s, r);
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
