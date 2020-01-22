#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    static bool cmp(string& a, string& b)
    {
        int blen = b.size();
        int alen = a.size();
        int i = 0;
        while (i < (alen + blen) && b[i%blen] == a[i%alen])
        {
            i++;
        }

        return a[i%alen] > b[i%blen];
    };
    
public:
    string largestNumber(vector<int>& nums) {
        string result;
        vector<string> numstr(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            numstr[i] = to_string(nums[i]);
        }
        
        sort(numstr.begin(), numstr.end(), cmp);
        for (string& s : numstr)
        {
            result += s;
        }
        
        return (result[0] == '0') ? "0" : result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {3,30,34,5,9};
    cout<<s.largestNumber(nums)<<endl;
    return 0;
}
