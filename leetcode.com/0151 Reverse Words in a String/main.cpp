#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
private:
    string rjoin(vector<string> vs, string delimiter) {
        if (vs.empty()) return "";
        string result = "";
        for (auto it = vs.rbegin(); it != vs.rend()-1; ++it) {
            result += ((*it) + " ");
        }
        return result += vs[0];
    }
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string tmp_s;
        vector<string> vs;
        while (ss>>tmp_s) vs.push_back(tmp_s);
        return rjoin(vs, " ");
    }
};