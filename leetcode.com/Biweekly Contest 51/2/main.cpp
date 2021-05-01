#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

// struct cmp {
//     bool operator()(int a, int b){
//         return a > b;
//     }
// };

auto cmp = [](int a, int b) {
    return a > b;
};

class SeatManager {
private:
    vector<int> v;
    int sz;
public:
    SeatManager(int n): v(n), sz(n) {
        iota(v.begin(), v.end(), 1);
        make_heap(v.begin(), v.end(), cmp);
    }
    
    int reserve() {
        pop_heap(v.begin(), v.begin()+sz, cmp);
        return v[--sz];
    }
    
    void unreserve(int seatNumber) {
        v[sz++] = seatNumber;
        push_heap(v.begin(), v.begin()+sz, cmp);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
