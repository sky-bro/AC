#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
      // sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[1] == b[1] ? b[0] < a[0] : a[1] < b[1];});
      sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[1] < b[1];});
      int n = intervals.size();
      int a = -1, b = -1; // largest, second_larget
      int res = 0;
      for (auto &interval: intervals) {
        if (interval[0] > a) {
          res += 2;
          a = interval[1];
          b = a-1;
        } else if (interval[0] > b) {
          ++res;
          // b = a;
          b = a == interval[1] ? a-1 : a;
          a = interval[1];
        }
      }
      return res;
    }
};

int main(int argc, char const *argv[])
{
  Solution s;
  vector<vector<int>> intervals = {{16,18},{11,18},{15,23},{1,16},{10,16},{6,19},{18,20},{7,19},{10,11},{11,23},{6,7},{23,25},{1,3},{7,12},{1,13},{23,25},{10,22},{23,25},{0,19},{0,13},{7,12},{14,19},{8,17},{7,23},{4,24}};
  cout<<s.intersectionSizeTwo(intervals)<<endl;
  return 0;
}
