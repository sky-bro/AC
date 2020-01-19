#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> range_pairs;
        for (int i = 0; i <= n; ++i) {
            if (ranges[i] == 0) continue;
            range_pairs.push_back(pair<int, int>(i - ranges[i], i + ranges[i]));
        }
        sort(range_pairs.begin(), range_pairs.end(), [](pair<int, int> &range_pair1, pair<int, int> &range_pair2){return range_pair1.second > range_pair2.second;});
        int pair_num = range_pairs.size();
        int result = 0, last_right = 0, idx = 0;
        while (true) {
            for (idx = 0; idx < pair_num && range_pairs[idx].second > last_right; ++idx) {
                if (range_pairs[idx].first <= last_right) break;
            }
            if ( idx >= pair_num || range_pairs[idx].second <= last_right ) return -1;
            ++result;
            last_right = range_pairs[idx].second;
            if (last_right >= n) return result;
        }
        
    }
};

int main(int argc, char const *argv[])
{
    vector<int> ranges = {0,5,0,3,3,3,1,4,0,4};
    int n = 9;
    ranges = {0,0,0,0};
    n = 3;
    Solution s;
    cout<<s.minTaps(n, ranges)<<endl;
    return 0;
}
