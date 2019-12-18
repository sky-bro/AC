#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int sum_words_len = 0;
        for (int l = 0, r = 0; l < n; ) {
            // 最后一行
            if (r == n) {
                string tmp = words[l];
                for (int i = l + 1; i < n; ++i) {
                    tmp += " "+words[i];
                }
                for (int i = sum_words_len + r - l; i <= maxWidth; ++i) {
                    tmp.push_back(' ');
                }
                result.push_back(tmp);
                break;
            }
            // 不是最后一行，看该行是否能再放下words[r]
            sum_words_len += words[r].length();
            if (sum_words_len + r - l > maxWidth) {
                // 不能放下，push该行，words[r]留到下一行
                string tmp = words[l];
                if (r - l == 1) {
                    for (int i = tmp.length()+1; i <= maxWidth; ++i) {
                        tmp.push_back(' ');
                    }
                } else {
                    sum_words_len -= words[r].length();
                    int needed_spaces = maxWidth - sum_words_len;
                    for (int i = 1; i <= r - l - 1; ++i) {
                        int sigle_needed_spaces = needed_spaces / (r - l - i) + (needed_spaces % (r - l - i) != 0);
                        for (int j = 0; j < sigle_needed_spaces; ++j) {
                            tmp.push_back(' ');
                        }
                        needed_spaces -= sigle_needed_spaces;
                        tmp += words[l + i];
                    }
                }
                result.push_back(tmp);
                l = r;
                sum_words_len = 0;
            } else {
                ++r;
            }
        }
        return result;
    }
};


int main(int argc, char const *argv[])
{
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    Solution s;
    s.fullJustify(words, 16);
    return 0;
}
