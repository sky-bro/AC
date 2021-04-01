#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class TreeAncestor {
private:
    int h;
    vector<vector<int>> pa;
public:
    TreeAncestor(int n, vector<int>& parent): h(max(ceil(log2(n)), 1.)), pa(n, vector<int>(h, -1)) {
        for (int i = 0; i < n; ++i) pa[i][0] = parent[i];
        for (int i = 1; i < h; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pa[j][i-1] != -1)
                    pa[j][i] = pa[pa[j][i-1]][i-1];
            }
        }
    }
    
    int getKthAncestor(int x, int k) {
        for (int i = h-1; i >= 0 && x != -1; --i) {
            if ((1 << i) & k) {
                x = pa[x][i];
            }
        }
        return x;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
