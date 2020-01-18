#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ans, temp;
        while(ss >> temp)   ans = " " + temp + ans;
        return ans.empty()?ans:ans.substr(1);
    }
};