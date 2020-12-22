#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int perm[26];
int perm2[26];

class Solution {
    private:
    int len;
    bool chk(const string &word, const string &pattern) {
        memset(perm, -1, sizeof(perm));
        memset(perm2, -1, sizeof(perm2));
        for (int i = 0; i < len; ++i ) {
            int idx = word[i]-'a', idx2 = pattern[i] - 'a';
            if (perm[idx] == -1) {
                perm[idx] = idx2;
            }
            if (perm2[idx2] == -1) {
                perm2[idx2] = idx;
            }
            if (perm[idx] != idx2 || perm2[idx2] != idx) return false;
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        len = words[0].size();
        vector<string> res; 
        for (const string &word: words) {
            if (chk(word, pattern)) res.push_back(word);
        }
        return res;
    }
};
