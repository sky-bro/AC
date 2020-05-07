#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
private:
    void helper(char *buf, int l, int r) {
        vector<pair<int, int>> parts; // (part_start, part_len)
        int i = l;
        while (i < r) {
            bool basic = true;
            int cnt = 1, len = 1;
            while (cnt) {
                if (buf[i+len] == '1') {
                    if (cnt != len) basic = false;
                    ++cnt;
                } else {
                    --cnt;
                }
                ++len;
            }
            if (!basic) helper(buf, i+1, i+len-1);
            parts.emplace_back(i, len);
            i += len;
        }
        sort(parts.begin(), parts.end(), [&](pair<int,int>&a, pair<int,int>&b){
            // it's ok to either use length a.second or b.second
            return strncmp(buf+a.first, buf+b.first, a.second) > 0;
        });
        char *buf2 = new char[r-l];
        i = 0;
        for (auto& p: parts) {
            for (int j = p.first; j < p.first + p.second; ++j) {
                buf2[i++] = buf[j];
            }
        }
        strncpy(buf+l, buf2, r-l);
        delete [] buf2;
    }
public:
    string makeLargestSpecial(string S) {
        int n = S.length(); // if (n == 2) return S;
        char *buf = new char[n+1]; buf[n] = 0;
        strncpy(buf, S.c_str(), n);
        helper(buf, 0, n); // helper(buf, 1, n-1);
        string res(buf);
        delete [] buf;
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string S;
    while (cin>>S) {
        cout<<s.makeLargestSpecial(S)<<endl;
    }
    return 0;
}
