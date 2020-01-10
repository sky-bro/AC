#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // invalid input
        // assert(beginWord.size() == endWord.size());
        // trivial question

        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (beginWord == endWord || !wordSet.count(endWord) ) return 0;

        unordered_set<string> set1{beginWord}, set2{endWord};
        wordSet.erase(endWord);
        wordSet.erase(beginWord); // if existed

        int step = 1;
        while(!set1.empty()) {

            // bfs the graph with every possible valid next node(in the wordSet)
            unordered_set<string> nextLevel;
            for (string word : set1) { // can't be reference, unchangable!
                for (char & c : word) {
                    char original_c = c;
                    // change char in place(reference)
                    for (c = 'a'; c <= 'z'; ++c) {
                        if (set2.count(word))
                            return step + 1; // move forward one more step
                        else if(wordSet.count(word)) {
                            wordSet.erase(word);
                            nextLevel.insert(word);
                        }
                    }
                    c = original_c;
                }
            }

            // increase the step, swap the sets if necessary
            swap(set1, nextLevel);
            if (set1.size() > set2.size())
                swap(set1, set2);
            ++step;
        }

        return 0;
    }
};