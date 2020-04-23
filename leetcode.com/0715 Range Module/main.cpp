#include <iostream>
#include <vector>
#include <map>

using namespace std;

// C++, vector O(n) and map O(logn), compare two solutions
// https://leetcode.com/problems/range-module/discuss/108912/C%2B%2B-vector-O(n)-and-map-O(logn)-compare-two-solutions

class RangeModule {
private:
    map<int, int> m;
public:
    void addRange(int left, int right) {
        auto l = m.upper_bound(left), r = m.upper_bound(right); 
        if (l != m.begin()) {
            l--;
            if (l->second < left) l++;
        }
        if (l != r) { // r >= l
            left = min(left, l->first);
            right = max(right, (--r)->second);
            m.erase(l,++r); // erase intervals covered by [left, right)
        } // else { ... } // [left, right) is new interval
        m[left] = right; // add interval
    }
    
    bool queryRange(int left, int right) {
        auto it = m.upper_bound(left);
        if (it == m.begin() || (--it)->second < right) return false;
        return true;
    }
    
    void removeRange(int left, int right) {
        auto l = m.upper_bound(left), r = m.upper_bound(right); 
        if (l != m.begin()) {
            l--;
            if (l->second < left) l++;
        }
        if (l == r) return; // [left ,right) is new interval, no need to remove
        int l1 = min(left, l->first), r1 = max(right, (--r)->second);
        m.erase(l, ++r); // remove intervals covered / overlapped
        // re-construct intervals at two ends
        if (l1 < left) m[l1] = left;
        if (r1 > right) m[right] = r1;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
