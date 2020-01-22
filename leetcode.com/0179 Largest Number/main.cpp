#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string& a, string& b) {
    return a + b > b + a;
}

class Solution {
private:
    string join(vector<string>& nums) {
        string result = "";
        for (string &num: nums) {
            result += num;
        }
        return result;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums_str;
        for (int num: nums) nums_str.push_back(to_string(num));
        sort(nums_str.begin(), nums_str.end(), cmp);
        string result = join(nums_str);
        if (result.empty() || result[0] == '0') return "0";
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {3,30,34,5,9};
    cout<<s.largestNumber(nums)<<endl;
    return 0;
}
