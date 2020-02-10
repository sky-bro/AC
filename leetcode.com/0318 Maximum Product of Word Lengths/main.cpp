#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    inline uint32_t get_word_bits(string &word) {
        uint32_t word_bits = 0;
        for (char c: word) {
            word_bits |= (1 << (c-'a'));
        }
        return word_bits;
    }
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if (n < 2) return 0;
        int len1, max_product = 0;
        vector<uint32_t> words_bits;
        for (string& word: words) {
            words_bits.push_back(get_word_bits(word));
        }
        for (int i = 0; i < n - 1; ++i) {
            len1 = words[i].length();
            for (int j = i+1; j < n; ++j) {
                if ((words_bits[i] & words_bits[j]) == 0) {
                    max_product = max(max_product, int(len1 * words[j].length()));
                }
            }
        }
        return max_product;
    }
};