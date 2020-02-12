#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder == "#") return true;
        istringstream ISS(preorder);
        string s;
        vector<int> stk;
        int len = 0;
        bool solved = false;
        while (getline(ISS, s, ',')) {
            if (solved) return false;
            if (s == "#") {
                if (len == 0) return false;
                else if (stk[len-1] == 0) {
                    stk[len-1] = 1;
                } else/* if (stk[len-1] == 1)*/ {
                    stk[len-1] = 2;
                    while (len && stk[len-1] == 2) {
                        stk.pop_back();
                        --len;
                    }
                    if (len == 0) solved = true;
                }
            } else {
                stk.push_back(0);
                if (len) {
                    stk[len-1]++;
                }
                ++len;
            }
        }
        return len == 0;
    }
};

int main(int argc, char const *argv[])
{
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"; // true
    preorder = "9,3,4,#,#,1,#,#,#,2,#,6,#,#";
    Solution s;
    while (cin>>preorder) {
        cout<<s.isValidSerialization(preorder)<<endl;
    }
    return 0;
}
