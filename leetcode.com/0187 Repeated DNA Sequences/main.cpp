#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/repeated-dna-sequences/discuss/420527/Easy-Hashmap-bit-manipulation-solution-C%2B%2B
class Solution {
public:
    int char_to_bit(char c){
        if(c=='A') return 0;
        if(c=='C') return 1;
        if(c=='G') return 2;
        if(c=='T') return 3;
        return 0;
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        int n= s.size(), mask=0, bitmask=(1<<20)-1;
        if(n==0) return {};
        unordered_map<int, int> ht;
        vector<string> result;
        
        for(int i=0; i<10; i++){
            mask= (mask<<2) | char_to_bit(s[i]);
        }
        ht[mask]++;
        
        for(int i=10; i<n; i++){
            mask= ((mask<<2) & bitmask) | char_to_bit(s[i]);
            if(ht.find(mask)!=ht.end() && ht[mask]==1)
                result.push_back(s.substr(i-9, 10));
            ht[mask]++;
        }
        
        
        return result;
        
    }
};