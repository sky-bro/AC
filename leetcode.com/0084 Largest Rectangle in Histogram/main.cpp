// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxSize = 0, len = heights.size();
        for (int i = 0; i <= len; i++) {
            int h = (i == len ? 0 : heights[i]);
            if (s.empty() || h >= heights[s.top()])
                s.push(i);
            else {
                int tmp = s.top();
                s.pop();
                int tmpSize = heights[tmp] * (s.empty() ? i : (i - 1 - s.top()));
                maxSize = max(maxSize, tmpSize);
                i--;
            }
        }
        return maxSize;
    }
};