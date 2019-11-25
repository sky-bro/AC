#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long long ret = atoll(str.c_str());
        if (ret < INT32_MIN) return INT32_MIN;
        if (ret > INT32_MAX) return INT32_MAX;
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.myAtoi("4193 with words")<<endl;
    cout<<s.myAtoi("words and 987")<<endl;
    cout<<s.myAtoi("91283472332")<<endl;
    cout<<s.myAtoi("-91283472332")<<endl;
    return 0;
}
