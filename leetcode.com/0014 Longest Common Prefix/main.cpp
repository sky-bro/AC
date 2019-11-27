#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string res = "";
        int n = INT32_MAX;
        char c;
        for (string &str: strs){
            if (str.length() < n) n = str.length();
        }
        for (int i = 0; i < n; ++i) {
            c = strs[0][i];
            for (string &str: strs){
                if (str[i] != c) return res;
            }
            res.push_back(c);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
