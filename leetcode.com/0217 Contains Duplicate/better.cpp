#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        sort(begin(nums), end(nums));
        return adjacent_find(begin(nums), end(nums)) != cend(nums);
    }
};

/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        try {
            sort(begin(nums), end(nums), [](int a, int b) {
                if (a == b)
                    throw runtime_error("duplicate found!");
                
                return a < b;
            });
        } catch (const runtime_error&) {
            return true;
        }
        
        return false;
    }
};
*/
