#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int min_wordlen, max_wordlen, n;
    bool _wordBreak(string &s, int idx, unordered_set<string> & word_set, vector<char> &dp) {
        if (idx == n) return true;
        if (dp[idx]) return dp[idx] == 1;
        for (int word_len = min_wordlen; word_len <= max_wordlen && idx + word_len <= n; ++word_len) {
            if (word_set.count(s.substr(idx, word_len)) && _wordBreak(s, idx+word_len, word_set, dp)) {
                
                return dp[idx] = true;
            }
        }
        dp[idx] = 2;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        if (n == 0) return false;
        if (wordDict.empty()) return false;
        min_wordlen = wordDict[0].length(), max_wordlen = min_wordlen;
        unordered_set<string> word_set;
        vector<char> dp(n);

        for (auto& word: wordDict) {
            word_set.insert(word);
            int word_len = word.length();
            if (word_len < min_wordlen) min_wordlen = word_len;
            else if (word_len > max_wordlen) max_wordlen = word_len;
        }

        return _wordBreak(s, 0, word_set, dp);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> word_dict = {"leet", "code"};
    cout<<s.wordBreak("leetcode", word_dict)<<endl;
    return 0;
}
