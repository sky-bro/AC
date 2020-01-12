#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    bool cmp_str(int idx, int len, const string &str) {
        for (int i = idx; i < idx + len; ++i) {
            if (str[i] != str[i+len]) return false;
        }
        return true;
    }
public:
    int distinctEchoSubstrings(string text) {
        int n = text.length();
        vector<bool> is_first_valid(n/2+1, false);
        // int result = n/2;
        unordered_set<string> st;


        for (int len = 1; len <= n/2; ++len) {
            if (cmp_str(0, len, text)) {
                is_first_valid[len] = true;
                st.insert(text.substr(0, len));
            }
        }

        for (int len = 1; len <= n/2; ++len) {
            for (int i = 1; i <= n - 2 * len; ++i) {
                if (is_first_valid[len]) {
                    if (text[i-1+len] == text[i-1+len+len]) {
                        st.insert(text.substr(i, len));
                    } else {
                        is_first_valid[len] = false;
                    }
                } else {
                    if (text[i-1] != text[i-1+len] && cmp_str(i, len, text)) {
                        is_first_valid[len] = true;
                        st.insert(text.substr(i, len));
                    }
                }
            }
        }
        return st.size();
    }
};

int main(int argc, char const *argv[])
{
    string text = "leetcodeleetcode";
    Solution s;

    cout<<s.distinctEchoSubstrings(text)<<endl;
    return 0;
}
