#include <iostream>
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

/**
 * use random strategy, guess too many times...
 */
class Solution {
   public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0, x = 0; i < 10 && x < 6; ++i) {
            vector<string> wordlist2;
            const string& guess = wordlist[random() % wordlist.size()];
            x = master.guess(guess);
            for (const auto& word : wordlist) {
                if (match(word, guess) == x) {
                    wordlist2.push_back(word);
                }
            }
        }
    }
};
