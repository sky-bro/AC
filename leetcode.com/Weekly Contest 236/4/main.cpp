#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

typedef long long ll;
class MKAverage {
private:
    int m, mm, K;
    vector<int> A;
    multiset<int> L, M, R;
    ll S;
public:
    MKAverage(int m, int k): m(m), mm(m - 2*k), K(k), S(0) {}

    int adjust(multiset<int> &a, multiset<int> &b, int n) {
        int diff = 0; // sum(a) diff
        if (a.size() < n) {
            if (!b.empty()) {
                auto it = b.begin();
                diff += *it;
                a.insert(*it);
                b.erase(it);
            }
        } else if (a.size() > n) {
            auto it = a.rbegin();
            diff -= *it;
            b.insert(*it);
            a.erase(prev(a.end()));
        }
        return diff;
    }
    
    void addElement(int num) {
        A.push_back(num);
        if (L.empty() || *L.rbegin() >= num) {
            L.insert(num);
        } else if (M.empty() || *M.rbegin() >= num) {
            M.insert(num);
            S += num;
        } else {
            R.insert(num);
        }
        if (A.size() > m) {
            int v = A[A.size() - 1 - m];
            if (v <= *L.rbegin()) {
                L.erase(L.find(v));
            } else if (v <= *M.rbegin()) {
                M.erase(M.find(v));
                S -= v;
            } else {
                R.erase(R.find(v));
            }
        }
        S -= adjust(L, M, K);
        S += adjust(M, R, mm);
    }
    
    int calculateMKAverage() {
        if (A.size() < m) return -1;
        return S / mm;
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
