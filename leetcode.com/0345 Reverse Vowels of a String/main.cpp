#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.length() - 1;
        bool mp[128]{};
        mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = true;
        mp['A'] = mp['E'] = mp['I'] = mp['O'] = mp['U'] = true;
        while (l < r) {
            for (; l < r && !mp[s[l]]; ++l);
            for (; l < r && !mp[s[r]]; --r);
            if (l < r) swap(s[l++], s[r--]);
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str;
    while (cin>>str) {
        cout<<s.reverseVowels(str)<<endl;
    }
    return 0;
}
