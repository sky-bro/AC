#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// ref:
// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/discuss/85541/C%2B%2B-128m-Solution-Real-O(1)-Solution
class RandomizedCollection {
 private:
  vector<pair<int, int>> nums;
  unordered_map<int, vector<int>> m;

 public:
  /** Initialize your data structure here. */
  RandomizedCollection() {
    nums.clear();
    m.clear();
  }

  /** Inserts a value to the collection. Returns true if the collection did not
   * already contain the specified element. */
  bool insert(int val) {
    bool res = m.find(val) == m.end();
    m[val].push_back(nums.size());
    nums.emplace_back(val, m[val].size() - 1);
    return res;
  }

  /** Removes a value from the collection. Returns true if the collection
   * contained the specified element. */
  bool remove(int val) {
    auto it = m.find(val);
    if (it == m.end()) return false;
    auto last = nums.back();
    m[last.first][last.second] = it->second.back();
    nums[it->second.back()] = last;
    it->second.pop_back();
    if (it->second.empty()) m.erase(it);
    nums.pop_back();
    return true;
  }

  /** Get a random element from the collection. */
  int getRandom() { return nums[rand() % nums.size()].first; }
};