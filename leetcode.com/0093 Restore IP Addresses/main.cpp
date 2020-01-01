#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> result;
    size_t n;
    void _restoreIpAddresses(const string &s, size_t idx, vector<int> &parts_len) {
        if (parts_len.size() == 4) {
            string tmp = s.substr(0, parts_len[0]) + "." 
                + s.substr(parts_len[0], parts_len[1]) + "." 
                + s.substr(parts_len[0]+parts_len[1], parts_len[2]) + "." 
                + s.substr(parts_len[0]+parts_len[1]+parts_len[2], parts_len[3]);
            result.push_back(tmp);
            return;
        }

        int min_len = (n-idx) - 3*(3-parts_len.size());
        if (min_len < 1) min_len = 1;
        int max_len = (n-idx) - (3-parts_len.size());
        if (max_len > 3) max_len = 3;
        for (int part_len = min_len; part_len <= max_len; ++part_len) {
            if (part_len == 1) {
                parts_len.push_back(1);
                _restoreIpAddresses(s, idx+1, parts_len);
                parts_len.pop_back();
            } else if (part_len == 2) {
                if (s[idx] == '0') return;
                parts_len.push_back(2);
                _restoreIpAddresses(s, idx+2, parts_len);
                parts_len.pop_back();
            } else if (part_len == 3) {
                if (s[idx] == '0' || s[idx] > '2' || s[idx] == '2' && (s[idx+1] > '5' || s[idx+1] == '5' && s[idx+2] > '5')) return;
                parts_len.push_back(3);
                _restoreIpAddresses(s, idx+3, parts_len);
                parts_len.pop_back();
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        n = s.length();
        vector<int> parts_len;
        _restoreIpAddresses(s, 0, parts_len);
        return result;
    }
};