#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, h;
        int area, max_area = 0;
        for (; l < r; ){
            h = min(height[l], height[r]);
            area = h * (r - l);
            if (area > max_area) max_area = area;
            if (height[l] < height[r]) {
                for (; l < r && height[l] <= h; ++l);
            } else {
                for (; l < r && height[r] <= h; --r);
            }
            if (l >= r) break;
        }
        return max_area;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<s.maxArea(height)<<endl;
    return 0;
}
