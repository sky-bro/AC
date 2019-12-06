#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prevStr = countAndSay(n-1);
        char prev_c = prevStr[0];
        int cnt = 0;
        string result = "";
        for (auto c: prevStr) {
            if (c == prev_c) {
                ++cnt;
                continue;
            }
            result.push_back(cnt+'0');
            result.push_back(prev_c);
            prev_c = c;
            cnt = 1;
        }
        result.push_back(cnt+'0');
        result.push_back(prev_c);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    /*
        1.     1
        2.     11
        3.     21
        4.     1211
        5.     111221 
        6.     312211
        7.     13112221
        8.     1113213211
        9.     31131211131221
       10.     13211311123113112211
    */
    cout<<s.countAndSay(1)<<endl;
    cout<<s.countAndSay(5)<<endl;
    cout<<s.countAndSay(10)<<endl;
    return 0;
}
