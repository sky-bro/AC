#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// ref: Random Guess and Minimax Guess with Comparison
// https://leetcode.com/problems/guess-the-word/discuss/133862/Random-Guess-and-Minimax-Guess-with-Comparison

// This is the Master's API interface.
// You should not implement it, or speculate about its implementation
class Master {
 public:
  int guess(string word);
};

int match(const string& a, const string& b) {
    int cnt = 0;
    for (int i = 0; i < 6; ++i) {
        if (a[i] == b[i]) ++cnt;
    }
    return cnt;
}

class Solution {
   public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0, x = 0; i < 10 && x < 6; ++i) {

            unordered_map<string, int> cnts;
            for (string& a : wordlist) {
                for (string& b : wordlist) {
                    if (match(a, b) == 0) {
                        cnts[a]++;
                    }
                }
            }

            pair<string, int> guess = {wordlist[0], INT32_MAX};
            for (string &word : wordlist) {
                if (cnts[word] < guess.second) {
                    guess.first = word;
                    guess.second = cnts[word];
                }
            }
            
            vector<string> wordlist2;
            x = master.guess(guess.first);
            for (string &word: wordlist) {
                if (match(word, guess.first) == x) {
                    wordlist2.push_back(word);
                }
            }
            wordlist = wordlist2;
        }
    }
};
