#include <iostream>
#include <vector>

using namespace std;

class SummaryRanges {
private:
    vector<vector<int>> intervals;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        intervals.clear();
    }
    
    void addNum(int val) {
        vector<int> tmp_interval = {val, val};
        int idx = lower_bound(intervals.begin(), intervals.end(), tmp_interval) - intervals.begin();
        // insert and merge right side
        if (idx == intervals.size()) {
            intervals.push_back(tmp_interval);
        } else {
            if (intervals[idx][0] <= val + 1) {
                intervals[idx][0] = min(intervals[idx][0], val);
            } else {
                intervals.insert(intervals.begin()+idx, tmp_interval);
            }
        }

        // merge left side
        if (idx == 0) return;
        if (intervals[idx-1][1] == intervals[idx][0] - 1) {
            intervals[idx-1][1] = intervals[idx][1];
            intervals.erase(intervals.begin() + idx);
        } else if (intervals[idx-1][1] >= intervals[idx][0]) {
            intervals.erase(intervals.begin() + idx);
        }
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
