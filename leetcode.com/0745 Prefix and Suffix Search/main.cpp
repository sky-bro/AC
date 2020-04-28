#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

struct Trie {
  vector<int> weights;
  unordered_map<char, Trie*> children;
  Trie(){}
  ~Trie() {
    for (auto &p: children) {
      delete p.second;
    }
  }
};

class WordFilter {
private:
  Trie *t1, *t2;
public:
    ~WordFilter() {
      delete t1;
      delete t2;
    }
    WordFilter(vector<string>& words) {
        t1 = new Trie;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
          Trie* pn = t1;
          for (char c: words[i]) {
            pn->weights.push_back(i);
            auto it = pn->children.find(c);
            Trie* next_pn = nullptr;
            if (it == pn->children.end()) {
              next_pn = new Trie;
              pn->children.emplace(c, next_pn);
            } else {
              next_pn = it->second;
            }
            pn = next_pn;
          }
          pn->weights.push_back(i);
        }

        t2 = new Trie;
        for (int i = 0; i < n; ++i) {
          Trie* pn = t2;
          for (int j = words[i].length() - 1; j >= 0; --j) {
            char c = words[i][j];
            pn->weights.push_back(i);
            auto it = pn->children.find(c);
            Trie* next_pn = nullptr;
            if (it == pn->children.end()) {
              next_pn = new Trie;
              pn->children.emplace(c, next_pn);
            } else {
              next_pn = it->second;
            }
            pn = next_pn;
          }
          pn->weights.push_back(i);
        }
    }
    
    int f(string prefix, string suffix) {
        Trie *pn = t1;
        for (char c: prefix) {
          auto it = pn->children.find(c);
          if (it == pn->children.end()) {
            return -1;
          }
          pn = it->second;
        }
        vector<int> &weights1 = pn->weights;

        pn = t2;
        for (int i = suffix.length()-1; i >= 0; --i) {
          char c = suffix[i];
          auto it = pn->children.find(c);
          if (it == pn->children.end()) {
            return -1;
          }
          pn = it->second;
        }
        vector<int> &weights2 = pn->weights;
        int i = weights1.size()-1, j = weights2.size()-1;
        while (i >= 0 && j >= 0 && weights1[i] != weights2[j]) {
          if (weights1[i] < weights2[j]) --j;
          else --i;
        }
        if (i < 0 || j < 0) return -1;
        return weights1[i];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

int main(int argc, char const *argv[])
{
  vector<string> words = {"apple"};
  WordFilter wf(words);
  cout<<wf.f("a", "b")<<endl;
  cout<<wf.f("a", "e")<<endl;
  cout<<wf.f("b", "")<<endl;
  return 0;
}

