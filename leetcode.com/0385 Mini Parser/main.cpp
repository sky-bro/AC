#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
 public:
  // Constructor initializes an empty nested list.
  NestedInteger();

  // Constructor initializes a single integer.
  NestedInteger(int value);

  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const;

  // Set this NestedInteger to hold a single integer.
  void setInteger(int value);

  // Set this NestedInteger to hold a nested list and adds a nested integer to
  // it.
  void add(const NestedInteger &ni);

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class Solution {
 public:
  NestedInteger deserialize(string s) {
    istringstream ISS(s);
    vector<NestedInteger> stk;
    char next_char = ISS.peek();
    int num;
    while (next_char != EOF) {
      switch (next_char) {
        case '[':
          stk.push_back(NestedInteger());
          ISS.get();
          break;
        case ']':
          if (stk.size() > 1) {
            stk[stk.size() - 2].add(stk.back());
            stk.pop_back();
          }
          ISS.get();
          break;
        case ',':
          ISS.get();
          break;
        default:  // num here
          NestedInteger tmp;
          ISS >> num;
          tmp.setInteger(num);
          if (stk.empty()) {
            stk.push_back(tmp);
          } else {
            stk[stk.size() - 1].add(tmp);
          }
          break;
      }
      next_char = ISS.peek();
    }
    return stk.back();
  }
};