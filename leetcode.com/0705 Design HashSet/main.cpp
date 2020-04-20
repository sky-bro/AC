#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

// space limited, to save space, we could use a set (ordered for binary search)

class MyHashSet {
 public:
  vector<bool> v;
  /** Initialize your data structure here. */
  MyHashSet() { v.resize(1024); }

  void add(int key) {
    while (key >= v.size()) v.resize(max(int(v.size() * 2), key+1));
    v[key] = true;
  }

  void remove(int key) {
    if (key < v.size()) v[key] = false;
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) { return key < v.size() && v[key]; }
};