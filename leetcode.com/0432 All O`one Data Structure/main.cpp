#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Bucket {
 public:
  int num;
  Bucket *pre, *next;
  unordered_set<string> strs;
  Bucket(Bucket *_pre, Bucket *_next, int _num, const string &str)
      : pre(_pre), next(_next), num(_num) {
    strs.emplace(str);
  }

  void remove_cur() {
    if (next) {
      next->pre = pre;
    }
    if (pre) {
      pre->next = next;
    }
    delete this;
  }

  Bucket *insert_before(const string &str, int _num) {
    Bucket *bucket = new Bucket(pre, this, _num, str);
    if (pre) pre->next = bucket;
    pre = bucket;
    return bucket;
  }

  Bucket *insert_after(const string &str, int _num) {
    Bucket *bucket = new Bucket(this, next, _num, str);
    if (next) next->pre = bucket;
    next = bucket;
    return bucket;
  }
};

// ref:
// https://leetcode.com/problems/all-oone-data-structure/discuss/91416/Java-AC-all-strict-O(1)-not-average-O(1)-easy-to-read
class AllOne {
 private:
  unordered_map<int, Bucket *> num2str;
  unordered_map<string, int> str2num;
  int max_num, min_num;

 public:
  /** Initialize your data structure here. */
  AllOne() {
    num2str.clear();
    str2num.clear();
    max_num = min_num = 0;
  }

  /** Inserts a new key <Key> with value 1. Or increments an existing key by 1.
   */
  void inc(string key) {
    int num = ++str2num[key];
    // empty list
    if (max_num == 0) {
      max_num = min_num = 1;
      num2str.emplace(1, new Bucket(nullptr, nullptr, 1, key));
      return;
    }

    // non-empty list
    if (num == 1) {
      // new key, may change min_num
      if (num2str.find(1) == num2str.end()) {
        num2str.emplace(1, num2str[min_num]->insert_before(key, 1));
        min_num = 1;
      } else {
        num2str[1]->strs.insert(key);
      }

    } else {
      // old key
      num2str[num - 1]->strs.erase(key);
      if (num2str.find(num) == num2str.end()) {
        num2str.emplace(num, num2str[num - 1]->insert_after(key, num));
        if (num - 1 == max_num) ++max_num;  // may change max_num
      } else {
        num2str[num]->strs.insert(key);
      }
      if (num2str[num - 1]->strs.empty()) {  // may change min_num
        if (num - 1 == min_num) ++min_num;
        num2str[num - 1]->remove_cur();
        num2str.erase(num - 1);
      }
    }
  }

  /** Decrements an existing key by 1. If Key's value is 1, remove it from the
   * data structure. */
  void dec(string key) {
    if (str2num.find(key) == str2num.end()) return;
    // may change min_num, max_num
    int num = --str2num[key];
    num2str[num + 1]->strs.erase(key);
    if (num != 0) {
      min_num = min(min_num, num);
      if (num2str.find(num) == num2str.end()) {
        num2str.emplace(num, num2str[num + 1]->insert_before(key, num));
      } else {
        num2str[num]->strs.insert(key);
      }
    } else {
      str2num.erase(key);
    }

    if (num2str[num + 1]->strs.empty()) {
      // may change min_num, max_num
      if (num == 0) {
        min_num = num2str[num + 1]->next ? num2str[num + 1]->next->num : 0;
      }
      if (max_num == num + 1) --max_num;
      num2str[num + 1]->remove_cur();
      num2str.erase(num + 1);
    }
  }

  /** Returns one of the keys with maximal value. */
  string getMaxKey() {
    return max_num == 0 ? "" : *num2str[max_num]->strs.begin();
  }

  /** Returns one of the keys with Minimal value. */
  string getMinKey() {
    return max_num == 0 ? "" : *num2str[min_num]->strs.begin();
  }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main(int argc, char const *argv[]) {
  AllOne one;
  // ["AllOne","inc","inc","inc","inc","inc","inc","dec",
  // "dec","getMinKey","dec","getMaxKey","getMinKey"]
  // [[],["a"],["b"],["b"],["c"],["c"],["c"],["b"],["b"],[],["a"],[],[]]
  one.inc("a");
  one.inc("b");
  one.inc("b");
  one.inc("c");
  one.inc("c");
  one.inc("c");
  one.dec("b");
  one.dec("b");
  cout << one.getMinKey() << endl;
  one.dec("a");
  cout << one.getMaxKey() << endl;
  cout << one.getMinKey() << endl;
  return 0;
}
