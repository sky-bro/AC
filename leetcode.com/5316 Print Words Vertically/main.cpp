#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> printVertically(string s) {
        stringstream sstream(s);
        string tmp_s;
        vector<string> result;
        int n = 0, cnt = 0;
        while (sstream>>tmp_s) {
            int i = 0;
            for (; i < tmp_s.length(); ++i) {
                if (i >= n) {
                    ++n;
                    result.push_back("");
                }
                for (int j = result[i].length(); j < cnt; ++j) result[i].push_back(' ');
                result[i].push_back(tmp_s[i]);
                
            }
            cnt++;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
