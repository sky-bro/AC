#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
 private:
  vector<int> nums;
  unordered_map<int, int> index;

 public:
  /** Initialize your data structure here. */
  RandomizedSet() {
    nums.clear();
    index.clear();
  }

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    auto it = index.find(val);
    if (it != index.end()) return false;
    index[val] = nums.size();
    nums.push_back(val);
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    auto it = index.find(val);
    if (it == index.end()) return false;
    int last_num = nums.back();
    index[last_num] = it->second;
    nums[it->second] = last_num;
    nums.pop_back();
    index.erase(it);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() { return nums[rand() % nums.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */