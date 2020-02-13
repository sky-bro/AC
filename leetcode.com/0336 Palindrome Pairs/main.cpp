#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int n;
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        n = words.size();
        unordered_map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[words[i]] = i;
        }
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            string &word = words[i];
            string word_rev(word.rbegin(), word.rend());
            if (word != word_rev) {
                auto it = mp.find(word_rev);
                if (it != mp.end()) {
                    res.push_back({it->second, i});
                }
            }
            int m = word.length();
            for (int left = 0, right; left < m; left = right) {
                right = left + 1;
                for (; right < m && word[right] == word[left]; ++right);
                if (left == 0) {
                    for (int len = 1; len < right; ++len) {
                        string other(word.rbegin(), word.rend()-len);
                        auto it = mp.find(other);
                        if (it != mp.end()) {
                            res.push_back({it->second, i});
                        }
                    }
                }

                if (right == m) {
                    for (int len = 1; len < right - left; ++len) {
                        string other(word.rbegin()+len, word.rend());
                        auto it = mp.find(other);
                        if (it != mp.end()) {
                            res.push_back({i, it->second});
                        }
                    }
                }
                
                int l = left-1, r = right;
                for (; l >= 0 && r < m && word[l] == word[r]; --l, ++r);
                if (l == -1) {
                    string other(word.rbegin(), word.rend()-r);
                    auto it = mp.find(other);
                    if (it != mp.end()) {
                        res.push_back({it->second, i});
                    }
                }
                
                if (r == m) {
                    string other(word.rbegin() + (r-1-l), word.rend());
                    auto it = mp.find(other);
                    if (it != mp.end()) {
                        res.push_back({i, it->second});
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> vs = {"", "aba"};
    s.palindromePairs(vs);
    return 0;
}
