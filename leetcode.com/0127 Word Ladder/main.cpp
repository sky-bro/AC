#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    int word_len, n;
    bool isNeighbor(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < word_len; ++i) {
            if (a[i] != b[i] && ++diff > 1) return false;
        }
        return true;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        word_len = beginWord.length();
        n = wordList.size();
        vector<bool> visited(n);
        queue<string> q;
        int len = 1;
        q.push(beginWord);
        while (!q.empty()) {
            int sz = q.size();
            ++len;
            for (int i = 0; i < sz; ++i) {
                string s = q.front(); q.pop();
                // if (s == endWord) return len;
                for (int j = 0; j < n; ++j) {
                    if (!visited[j] && isNeighbor(wordList[j], s)) {
                        if (wordList[j] == endWord) return len;
                        q.push(wordList[j]);
                        visited[j] = true;
                    }
                }
            }
        }
        return 0;
    }
};