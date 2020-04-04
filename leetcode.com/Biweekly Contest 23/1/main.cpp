#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        for (int i  = 1; i <= n; ++i) {
          int sum = 0, num = i;
          while (num) {
            sum += num % 10;
            num /= 10;
          }
          mp[sum]++;
        }
        int max_cnt = 0, max_cnt_cnt = 0;
        for (auto &p: mp) {
          if (p.second == max_cnt) ++max_cnt_cnt;
          else if (p.second > max_cnt) {
            max_cnt = p.second;
            max_cnt_cnt = p.second;
          }
        }
        return max_cnt_cnt;
    }
};