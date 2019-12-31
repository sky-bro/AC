#include <iostream>

using namespace std;

class Solution {
private:
    string s1, s2;
    bool _isScramble(size_t s1_left, size_t s1_right, size_t s2_left, size_t s2_right) {
        if (s1_left  == s1_right) {
            return s1[s1_left] == s2[s2_left];
        }

        for (size_t idx = s1.find(s2[s2_left], s1_left); idx <= s1_right; ) {
            if (idx == s1_left) {
                if (_isScramble(s1_left+1, s1_right, s2_left+1, s2_right)) return true;
            } else if (idx == s1_right) {
                if (_isScramble(s1_left, s1_right-1, s2_left+1, s2_right)) return true;
            } else {
                size_t right_len = s1_right - idx, left_len = idx - s1_left;
                
                if (_isScramble(s1_left, idx-1, s2_left+1, s2_left+left_len) && _isScramble(idx+1, s1_right, s2_left+left_len+1, s2_right) // left - left
                    || _isScramble(s1_left, idx-1, s2_left+right_len+1, s2_right) && _isScramble(idx+1, s1_right, s2_left+1, s2_left+right_len)) // left - right
                    return true;
            }
            idx = s1.find(s2[s2_left], ++idx);
        }
        return false;
    }
public:
    bool isScramble(string s1, string s2) {
        size_t s1_len = s1.length(), s2_len = s2.length();
        if (s1_len != s2_len) return false;
        if (s1_len == 0) return true;
        this->s1 = s1; this->s2 = s2;
        return _isScramble(0, s1_len-1, 0, s2_len-1);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string s1 = "great", s2 = "rgeat";
    cout<<boolalpha<<s.isScramble(s1, s2)<<endl; // true

    s1 = "abcd", s2 = "bcad";
    cout<<boolalpha<<s.isScramble(s1, s2)<<endl; // true

    while (cin>>s1>>s2) {
        cout<<boolalpha<<s.isScramble(s1, s2)<<endl;
    }
    return 0;
}
