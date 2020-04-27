#include <iostream>
#include <vector>

using namespace std;

// ref: [C++] Bellman Ford
// https://leetcode.com/problems/network-delay-time/discuss/109982/C%2B%2B-Bellman-Ford

// SLOW..
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dis(N + 1, INT32_MAX);
        dis[K] = 0;
        for (int i = 0; i < N; i++) {
            for (vector<int> e : times) {
                int u = e[0], v = e[1], w = e[2];
                if (dis[u] != INT32_MAX && dis[v] > dis[u] + w) { // relax
                    dis[v] = dis[u] + w;
                }
            }
        }

        // when I use max_element here, I get TLE...
        // int res = *max_element(dis.begin()+1, dis.end());
        int res = 0;
        for (int i = 1; i <= N; ++i) {
          if (dis[i] > res) res = dis[i];
        }
        return res == INT32_MAX ? -1 : res;
    }
};
