#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<int> res;

 public:
  vector<int> pancakeSort(vector<int>& arr) {
    int n = arr.size();
    while (--n) {
      auto it = max_element(arr.begin(), arr.begin() + n + 1);
      if (it - arr.begin() == n) continue;
      res.push_back(it - arr.begin() + 1);
      res.push_back(n + 1);
      reverse(arr.begin(), it+1);
      reverse(arr.begin(), arr.begin() + n + 1);
    }
    return res;
  }
};

/*
{3, 2, 4, 1}: {3,4,2,3}

{4,2,3,1}
{1,3,2,4}
{3,1,2,4}
{2,1,3,4}
*/

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> arr = {3, 2, 4, 1};
  s.pancakeSort(arr);
  return 0;
}
