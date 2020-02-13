#include <iostream>
#include <vector>

using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    vector<NestedInteger>::const_iterator left;
    vector<NestedInteger>::const_iterator right;
    NestedIterator *it;
public:
    NestedIterator(const vector<NestedInteger> &nestedList) {
        left = nestedList.begin();
        right = nestedList.end();
        if (left != right && left->isInteger() == false) {
            it = new NestedIterator(left->getList());
        }
    }

    int next() {
        while (left != right && left->isInteger() == false && it->hasNext() == false) {
            delete it;
            ++left;
            if (left != right && left->isInteger() == false) {
                it = new NestedIterator(left->getList());
            }
        }

        // illegal
        if (left == right) return -1;

        // sigle int
        if (left->isInteger()) {
            // ??? wtf... is this ok
            int res = left->getInteger();
            ++left;
            if (left != right && left->isInteger() == false) {
                it = new NestedIterator(left->getList());
            }
            return res;
        }

        // list
        // could list be empty? I suppose not, if it could be, then we have problem
        // turns out it could be empty
        int res = it->next();
        if (it->hasNext() == false) {
            delete it;
            ++left;
            if (left != right && left->isInteger() == false) {
                it = new NestedIterator(left->getList());
            }
        }
        return res;
    }

    bool hasNext() {
        while (left != right && left->isInteger() == false && it->hasNext() == false) {
            delete it;
            ++left;
            if (left != right && left->isInteger() == false) {
                it = new NestedIterator(left->getList());
            }
        }
        return left != right;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
