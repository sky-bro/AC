#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<string>> groupedAnagrams; // What we will return

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ourMap; // Map a string pattern to a list of 
        for (const auto& word : strs) { // string that match that pattern
            string temp = word; // Sort a copy of each word, keep it as a unique identifier 
            sort(temp.begin(), temp.end());
            ourMap[temp].push_back(word); // For all words that match a given sort, similar to a unique identifier,
        } // we add them to our list of words that match that identifier
        for (const auto& entry : ourMap) { // We iterate through our map, pushing all word collections
            groupedAnagrams.push_back(entry.second);  // into our result vector
        }
        return groupedAnagrams;
    }
};
