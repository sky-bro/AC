#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> map_s2t(255);
        vector<char> map_t2s(255);
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (map_s2t[s[i]]) {
                if (map_s2t[s[i]] != t[i]) return false;
            } else {
                map_s2t[s[i]] = t[i];
            }

            if (map_t2s[t[i]]) {
                if (map_t2s[t[i]] != s[i]) return false;
            } else {
                map_t2s[t[i]] = s[i];
            }
        }
        return true;
    }
};