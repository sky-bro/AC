#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    string m[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> vs;
    void generatePermutations(const string &digits, int pos, string& cur_str, int size) {
        if (size == pos) { // Once our string is the same length as the number of digits
            vs.push_back(cur_str);
            return;
        }
        for (auto c: m[digits[pos] - '2']) {
            cur_str.push_back(c);
            generatePermutations(digits, pos + 1, cur_str, size);
            cur_str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>(0);
        int n = digits.length();
        string cur_str = "";
        generatePermutations(digits, 0, cur_str, n);
        return vs;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> vs = s.letterCombinations("");
    cout<<"Count: "<<vs.size()<<endl;
    for (auto str: vs) {
        cout<<str<<" ";
    }
    cout<<endl;
    return 0;
}
