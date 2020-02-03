#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// use primes' product has a problem: https://leetcode.com/problems/group-anagrams/discuss/497843/problem-with-primes-product-solution
class Solution {
public:

    constexpr static array<int, 26> PRIMES = {
    2,  3,  5,  7, 11, 13, 17, 19, 23, 29, 31, 37,  41,
    43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<uint32_t, vector<string>> M;
        
        for (auto str : strs) {
        uint32_t p = 1;
        for (char c : str)
            p *= PRIMES[c-'a'];
        M[p].push_back(str);
        }
        
        vector<vector<string>> result;
        // result.reserve(M.size());
        for (auto a: M){
            result.push_back(move(a.second));
        }
        // for (auto it = M.begin(); it != M.end(); ++it)
        //   result.push_back(move(it->second));
        return result;
    }
};
