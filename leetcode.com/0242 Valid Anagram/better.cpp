#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26,0);
        for(char c: s) cnt[c-'a']++;
        for(char c: t) cnt[c-'a']--;
        for(int i: cnt) if(i!=0) return false;
        return true;
    }
};