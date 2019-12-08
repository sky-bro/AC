#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        if (r <= 1) return 0;
        int left_max = height[0], right_max = height[r], result = 0;
        while (l < r) {
            if (left_max < right_max) {
                if (height[++l] < left_max) {
                    result += left_max - height[l];
                } else {
                    left_max = height[l];
                }
            } else {
                if (height[--r] < right_max) {
                    result += right_max - height[r];
                } else {
                    right_max = height[r];
                }
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trap(height)<<endl;
    return 0;
}
