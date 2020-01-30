#include <iostream>
#include <vector>
#include <set>

using namespace std;

// https://leetcode.com/problems/contains-duplicate-iii/discuss/492402/NlogK-C%2B%2B-Sliding-Window-using-Multiset

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
        multiset<int> s;  	 
        // Using long long here for a corner case [-1,2147483647] k = 1 t = 2147483647
        using ll = long long; 
        for(int i = 0, len = (int)nums.size(); i < len; ++i){        
            // if window exceeds k + 1 elements we delete the first element
            if(i > k) s.erase(s.find(nums[i - k - 1]));  
            // if lower_bound does not satisfy the condition (<= t), we check with the preceeding element as well.
            if(auto it = s.lower_bound(nums[i]); (it != s.end() && abs(*it - (ll)nums[i]) <= t) || (it != s.begin() && abs(*prev(it) - (ll)nums[i]) <= t)) return true;
            s.insert(nums[i]);
        }
        return false;
   }
};