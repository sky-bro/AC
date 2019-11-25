// https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/296844/C%2B%2B-Sliding-WindowTwo-pointers-faster-than-99

/*
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
*/

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Sliding window 
        if (s.length() <= 1)
            return s.length();
        
        int hashmap[256] = {0};
        
        int begin = 0;
        int end = 0;
        int maxLenSeen = 0;
        int currentLen = 0;
        
        for(int i=0; i<s.size(); ++i)
        {
            hashmap[s[i]]++;
            // If we've already seen this value
            if (hashmap[s[i]] > 1)
            {
                end = i-1;
                //Move begin to the next possible place so that out substring defined by 
                //end-begin is of non-repeating characters again
                while(hashmap[s[i]] > 1 && begin <= end)
                {
                    hashmap[s[begin]]--;
                    begin++; //This is the beginning index for new unique string
                }
            }
            else
            {
                end = i;
            }
            currentLen = end-begin+1;
            if (currentLen > maxLenSeen) maxLenSeen = currentLen;
        }
        return maxLenSeen;
    }
};


string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}