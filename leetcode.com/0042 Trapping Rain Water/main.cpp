// https://leetcode.com/problems/trapping-rain-water/discuss/347671/simple-solutionorc%2B%2BorO(n)-solutionorwithout-stackordetailed-explanationorcomments

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) 
    {
       int l=0,r=height.size()-1,leftmax=0,rightmax=0,ans=0;
        while(l<r)
        {
            if(height[l]<height[r])// comparing the heights the one which is smaller is taken first
            {
                if(height[l]>=leftmax)
               {
                leftmax=height[l];// updating left max
                l++;
               }
               else if(height[l]<leftmax)
              {
                ans+=(leftmax-height[l]);//updating the answer and substracting height[l] to remove space //taken by bar of height[l] this is basically the amount of water above height[l]
                l++;
               }
            }
            else
            {
                if(height[r]>=rightmax)
                {
                    rightmax=height[r];// similarly for right index also
                    r--;
                }else
                {
                    ans+=(rightmax-height[r]);
                    r--;
                }
            }
        }
        return ans;
    }
};

/*

class Solution {
private:
    template <typename T>
	int findWaterTrapped(T bIter, T eItr) {
    int waterTrapped{}, highWaterLevel = numeric_limits<int>::min();
    // Climb up the mountain to the max element, find the high water mark, 
    // and if there is a casm, add that to the water trapped.
    while (bIter != eItr) {
        if (*bIter >= highWaterLevel) {
            highWaterLevel = *bIter;
        } else {
            waterTrapped += highWaterLevel - *bIter;
        }
        bIter++;
    }
    return waterTrapped;
}
    
public:
    int trap(vector<int>& waterField) {
        if (!waterField.size()) return 0; // Easy points.
		auto maxHeight = max_element(waterField.begin(), waterField.end()); // Iter to max element
		// or first occurance of highest element if there are two max elements.
		int distanceOfMax = distance(waterField.begin(), maxHeight); // Find out how far it is from 
		// the beginning of our water field.
		// Break the question into water from the left side to the max, and water from the right to the max.
		// Climb the hill inspecting any levels lower than the high water mark. 
		// DIVIDE AND CONQUER THE INTERVIEWER AAAAAAAAAAAAAAAAAAa!!!!!!
		
		return findWaterTrapped(waterField.begin(), waterField.begin() + distanceOfMax) +
        findWaterTrapped(waterField.rbegin(), waterField.rend() - distanceOfMax - 1); 
		// The second findWaterTrapped function can drop the -1 if we want to, since the max element's location
		// (whether its included or excluded in our array, never actually contributed towards trapping water.
		// That is the whole point of partitioning on the max element. :) At least I think it can be dropped (meaning. 
		// the max element is included). Test it and let me know :)
};

*/