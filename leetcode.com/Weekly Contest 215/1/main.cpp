#include <iostream>
#include <vector>

using namespace std;

class OrderedStream {
    private:
    int ptr;
    vector<string> v;
public:
    OrderedStream(int n) {
        v.clear();
        v.resize(n, "");
        ptr = 0;
    }
    
    vector<string> insert(int id, string value) {
        vector<string> res;
        v[--id] = value;
        if (id == ptr) {
            while (ptr < v.size() && v[ptr].length()) {
                res.push_back(v[ptr++]);
            }
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
