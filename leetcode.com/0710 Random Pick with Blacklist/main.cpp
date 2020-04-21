#include <iostream>
#include <vector>
#include <random>
#include <unordered_map>

using namespace std;

// ref: Java O(B) / O(1), HashMap
// https://leetcode.com/problems/random-pick-with-blacklist/discuss/144624/Java-O(B)-O(1)-HashMap
// this should be the right way to approch this problem
// I don't think other binary search solution is right...

class Solution {
private:
    mt19937 prng;
    uniform_int_distribution<> dis;
    unordered_map<int, int> mp;
public:
    Solution(int N, vector<int>& blacklist) {
        // for seed (this is a rng: random number generator)
        random_device rd;
        // prng: pseudo random number generator
        // prng will be more efficent than randome_device
        prng = mt19937(rd());
        

        int n = N - blacklist.size();
        dis = uniform_int_distribution<>(0, n-1);

        for (int b: blacklist) {
            // these don't need remap
            // but take the place: prevent others remap here
            if (b >= n) mp.emplace(b, -1);
        }

        --N; // number picked in [0, N)
        for (int b: blacklist) {
            if (b < n) { // remap these
                // place taken by some number in bloacklist
                while (mp.count(N)) --N; 
                // place available
                mp.emplace(b, N--);
            }
        }
    }
    
    int pick() {
        int k = dis(prng);
        auto it = mp.find(k);
        return it == mp.end() ? k : it->second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
