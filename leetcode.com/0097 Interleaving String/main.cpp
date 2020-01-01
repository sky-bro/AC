#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Time Limit Exceeded
class Solution0 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1_len = s1.length(), s2_len = s2.length(), s3_len = s3.length();
        if (s1_len + s2_len != s3_len) return false;

        stack<pair<int, int>> stk;
        stk.push(make_pair(0,0));

        while (!stk.empty()) {
            pair<int, int> p = stk.top(); stk.pop();
            if (p.first + p.second == s3_len) return true;
            if (p.first != s1_len && s1[p.first] == s3[p.first+p.second]) stk.push(make_pair(p.first+1, p.second));
            if (p.second != s2_len && s2[p.second] == s3[p.first+p.second]) stk.push(make_pair(p.first, p.second+1));
        }
        return false;
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1_len = s1.length(), s2_len = s2.length(), s3_len = s3.length();
        if (s1_len + s2_len != s3_len) return false;

        vector<bool> dp(s2_len+1);
        dp[0] = true;
        for (int c = 1; dp[c-1] && c <= s2_len && s2[c-1] == s3[c-1]; dp[c++] = true);
        for (int r = 1; r <= s1_len; ++r) {
            if (dp[0] && s1[r-1] == s3[r-1]) dp[0] = true;
            else dp[0] = false;
            for (int c = 1; c <= s2_len; ++c) {
                if (dp[c-1] && s2[c-1] == s3[r+c-1]) dp[c] = true;
                else if (dp[c] && s1[r-1] == s3[r+c-1]) dp[c] = true;
                else dp[c] = false;
            }
        }
        return dp[s2_len];
    }
};

int main(int argc, char const *argv[])
{
    string s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
    string s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
    string s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
    Solution s;
    cout<<boolalpha<<s.isInterleave(s1, s2, s3)<<endl;
    return 0;
}
