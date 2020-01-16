#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int min_wordlen, max_wordlen, n;
    vector<string> result;
    const string& join(const vector<string> vs, char c, string &s) {
        for (auto p = vs.begin(); p != vs.end(); ++p) {
            s += *p;
            if (p != vs.end() - 1) s += c;
        }
        return s;
    }
    bool _wordBreak(string &s, int idx, unordered_set<string> & word_set, vector<string> &path, vector<bool> &visited, vector<vector<string>> &dp) {
        if (idx == n) {
            string tmp_s;
            result.push_back(join(path, ' ', tmp_s));
            return true;
        }
        if (visited[idx]) {
            if (dp[idx].empty()) return false;
            for (auto &tmp_s: dp[idx]) {
                path.push_back(tmp_s);
                _wordBreak(s, idx + tmp_s.length(), word_set, path, visited, dp);
                path.pop_back();
            }
            return true;
        }
        
        for (int word_len = min_wordlen; word_len <= max_wordlen && idx + word_len <= n; ++word_len) {
            string tmp_s = s.substr(idx, word_len);
            if (word_set.count(tmp_s)) {
                path.push_back(tmp_s);
                if (_wordBreak(s, idx + word_len, word_set, path, visited, dp)) dp[idx].push_back(tmp_s);
                path.pop_back();
            }
        }
        visited[idx] = true;
        return !dp[idx].empty();
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        result.clear();
        if (n == 0 || wordDict.empty()) return result;
        min_wordlen = wordDict[0].length(), max_wordlen = min_wordlen;
        unordered_set<string> word_set;
        vector<bool> visited(n);
        vector<vector<string>> dp(n);

        for (auto& word: wordDict) {
            word_set.insert(word);
            int word_len = word.length();
            if (word_len < min_wordlen) min_wordlen = word_len;
            else if (word_len > max_wordlen) max_wordlen = word_len;
        }

        vector<string> path;
        _wordBreak(s, 0, word_set, path, visited, dp);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> word_dict = {"cat", "cats", "and", "sand", "dog"};
    string tmp_s = "catsanddog";
    auto vs = s.wordBreak(tmp_s, word_dict);
    cout<<vs.size()<<endl;
    cout<<vs[0]<<endl;
    cout<<vs[1]<<endl;

    return 0;
}
