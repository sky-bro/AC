#include <iostream>
#include <vector>


using namespace std;

class Solution {

private:
    int word_len, path_len, n;
    vector<vector<string>> result;
    bool isNeighbor(string &a, string &b) {
        int diff_cnt = 0;
        for (int i = 0; i < word_len; ++i) {
            if (a[i] != b[i] && ++diff_cnt > 1) {
                return false;
            }
        }
        return true;
    }
    void dfs(string &beginWord, string &endWord, vector<string> &wordList, vector<string> &path, vector<bool> &visited) {
        if (beginWord == endWord) {
            if (path.size() < path_len) {
                result.clear();
                path_len = path.size();
            }
            result.push_back(path);
            return;
        }

        // no need to find longer pathes
        if (path.size() == path_len) return;

        for (int i = 0; i < n; ++i) {
            if (!visited[i] && isNeighbor(beginWord, wordList[i])) {
                path.push_back(wordList[i]);
                visited[i] = true;
                dfs(wordList[i], endWord, wordList, path, visited);
                visited[i] = false;
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        word_len = beginWord.length();
        n = wordList.size();
        path_len = n + 1;
        vector<string> path;
        vector<bool> visited(n);
        path.push_back(beginWord);
        dfs(beginWord, endWord, wordList, path, visited);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    Solution s;
    s.findLadders(beginWord, endWord, wordList);
    return 0;
}
