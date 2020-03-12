#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Trie {
 public:
  unordered_map<char, Trie*> mp;
  bool isWord;
  int cnt;

  Trie() : isWord(false), cnt(0) {}
  Trie(vector<string>& words) : isWord(false), cnt(0) {
    for (string& word : words) {
      Trie* cur = this;
      for (char c : word) {
        auto it = cur->mp.find(c);
        if (it == cur->mp.end()) {
          Trie* next = new Trie();
          cur->mp.emplace(c, next);
        }
        cur = cur->mp[c];
        cur->cnt++;
      }
      cur->isWord = true;
    }
  }
  // ~Trie();

  Trie* find(const string& word) const {
    const Trie* cur = this;
    for (char c : word) {
      auto it = cur->mp.find(c);
      if (it == cur->mp.end()) return nullptr;
      cur = it->second;
    }
  }
};

class Solution {
 private:
  vector<string> res;
  bool dfs(string& word, int i, int n, Trie& trie, int min_cnt) {
    if (n == 0) return false;
    if (i == n) return true;
    Trie* cur = &trie;
    for (; i < n; ++i) {
      auto it = cur->mp.find(word[i]);
      if (it == cur->mp.end() || it->second->cnt < min_cnt) break;
      if (it->second->isWord && dfs(word, i + 1, word.length(), trie, 1))
        return true;
      cur = cur->mp[word[i]];
    }
    return false;
  }

 public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    res.clear();
    Trie trie(words);
    for (string& word : words) {
      if (dfs(word, 0, word.length() - 1, trie, 2)) res.push_back(word);
    }
    return res;
  }
};

template <typename T>
void printArr(const vector<T>& arr) {
  for (const T& t : arr) {
    cout << t << " ";
  }
  cout << endl;
}

int main(int argc, char const* argv[]) {
  Solution s;
  vector<string> words = {"cat", "cats",        "catsdogcats",
                          "dog", "dogcatsdog",  "hippopotamuses",
                          "rat", "ratcatdogcat"};
  words = {"a", "aa"};
  printArr(s.findAllConcatenatedWordsInADict(words));
  return 0;
}
