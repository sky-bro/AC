#include <iostream>
#include <vector>

using namespace std;

// naive implementation, could use a map (for binary search when clide) to improve

class MyHashMap {
public:
  vector<int> v;
    /** Initialize your data structure here. */
    MyHashMap() {
        v.resize(1024, -1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        if (key >= v.size()) v.resize(max(int(v.size()*2), key+1), -1);
        v[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return key < v.size() ? v[key] : -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if (key < v.size()) v[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
