// https://leetcode.com/problems/two-sum/discuss/256370/C%2B%2B-8ms-99.96(Runtime)-98.23(Memory)-with-comments
/*
Sort the vector(nums), and index[k] represents the original position of the kth number in sorted vector.
Use two pointers (=index number), one for the smaller number (start), the other for the larger (end), and compare nums[start]+nums[end] with target:
    If nums[start]+nums[end] = target, index[start] and index[end] are the answer.
    Else If nums[start]+nums[end] < target, move start to larger one ( start++ ) so that nums[start]+nums[end] becomes larger.
    Else if nums[start]+nums[end] > target, move end to smaller one ( end-- ) so that nums[start]+nums[end] becomes smaller.
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void swap(vector<int>& nums, int i, int j, int* index) {
	// Swap indices at the same time, to keep track of the original indices.
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    temp = index[i];
    index[i] = index[j];
    index[j] = temp;
}
int partition(vector<int>& nums, int start, int end, int* index) {
	// choose a `random' position
    int p = start + rand()%(end-start);
    swap(nums, p, end, index);
	
	// Now nums[end] is some random value in nums[start, end]
    int r = nums[end];
    int i = start - 1, j = start;
    for(; j < end; j++) {
        if(nums[j]<r) {
            i++;
            swap(nums, i, j, index);
        }
    }
    swap(nums, i+1, end, index);
    return i+1;
}
void quickSort(vector<int>& nums, int start, int end, int* index) {
    if(start<end) {
        int q = partition(nums, start, end, index);
        quickSort(nums, start, q-1, index);
        quickSort(nums, q+1, end, index);        
    }
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        map<int, int> m;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            auto iter = m.find(target - nums[i]);
            if (iter != m.end()) {
                v.push_back(i);
                v.push_back(iter->second);
                break;
            }
            m.insert({nums[i], i});
        }
        return v;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> vec{1,2,3,4};
    const vector<int> &v2 = s.twoSum(vec, 7);
    cout<<v2[0]<<endl;
    cout<<v2[1]<<endl;
    return 0;
}
