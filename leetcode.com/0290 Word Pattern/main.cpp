#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> left2right;
        unordered_map<string, char> right2left;
        int idx = 0, n = str.length();
        for (char c: pattern) {
            int len = 0;
            for (; idx + len < n && str[idx+len] != ' '; ++len);
            if (len == 0) return false;

            string tmp_str = str.substr(idx, len);

            if (left2right.count(c)) {
                if (left2right[c] != tmp_str) return false;
            } else {
                left2right[c] = tmp_str;
            }

            if (right2left.count(tmp_str)) {
                if (right2left[tmp_str] != c) return false;
            } else {
                right2left[tmp_str] = c;
            }

            idx += len + 1;
        }
        return true;
    }
};