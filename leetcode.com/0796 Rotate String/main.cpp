#include <iostream>
#include <vector>

using namespace std;

// ref: 1 Line C++
// https://leetcode.com/problems/rotate-string/discuss/118641/1-Line-C%2B%2B

class Solution {
public:
    bool rotateString(string A, string B) {
        return A.length() == B.length() && (A+A).find(B) != string::npos;
    }
};
