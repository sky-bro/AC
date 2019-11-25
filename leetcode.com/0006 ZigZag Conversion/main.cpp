#include <iostream>
#include <vector>

using namespace std;


/*
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;

        int n = s.length();
        int row = 0, down = 1; 
        vector<string> ss(numRows, "");
        for (int i = 0; i < n; ++i) {
            ss[row].push_back(s[i]);
            if (row == 0) {
                down = 1;
            } else if (row == numRows - 1){
                down = -1;
            }
            row += down;
        }
        string ret = "";
        for (auto x: ss){
            ret += x;
        }
        return ret;
    }
};