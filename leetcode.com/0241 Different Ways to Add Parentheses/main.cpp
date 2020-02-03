#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int n;
    vector<int> nums;
    vector<char> ops;
    vector<int> helper(int l, int r) {
        vector<int> result;
        if (l == r) return {nums[l]};
        for (int i = l; i < r; ++i) {
            auto left = helper(l, i);
            auto right = helper(i+1, r);
            for (int x: left) {
                for (int y: right) {
                    switch (ops[i])
                    {
                    case '+':
                        result.push_back(x+y);
                        break;
                    case '-':
                        result.push_back(x-y);
                        break;
                    case '*':
                        result.push_back(x*y);
                        break;
                    }
                }
            }
        }
        return result;
    }
public:
    vector<int> diffWaysToCompute(string input) {
        n = input.length();
        const char *input_cstr = input.c_str();
        bool get_num = true;
        for (int i = 0; i < n; get_num = !get_num) {
            if (get_num) {
                int tmp; int len;
                sscanf(input_cstr+i, "%d%n", &tmp, &len);
                i += len;
                nums.push_back(tmp);
            } else {
                ops.push_back(input_cstr[i++]);
                
            }
        }
        n = nums.size();
        return helper(0, n-1);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.diffWaysToCompute("2-1-1");
    return 0;
}
