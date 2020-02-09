#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// ref: https://leetcode.com/problems/jump-game-iv/discuss/502699/JavaC%2B%2B-BFS-Solution-Clean-code-O(N)

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; ++i) {
            map[arr[i]].push_back(i);
        }
        queue<int> *q = new queue<int>();
        queue<int> *q2 = new queue<int>();
        (*q).push(0);
        (*q2).push(n-1);
        vector<bool> *visited = new vector<bool>(n);
        vector<bool> *visited2 = new vector<bool>(n);
        (*visited)[0] = true;
        (*visited2)[n-1] = true;
        int steps = 0;
        while (true) {
            ++steps;
            if ((*q2).size() < (*q).size()) {
                swap(q, q2);
                swap(visited, visited2);
            }
            int sz = (*q).size();
            for (int i = 0; i < sz; ++i) {
                int idx = (*q).front(); (*q).pop();
                if (idx+1 < n && !(*visited)[idx+1]) {
                    if ((*visited2)[idx+1]) return steps;
                    // if (idx+1 == n-1) return steps;
                    (*visited)[idx+1] = true;
                    (*q).push(idx+1);
                }
                if (idx-1 >= 0 && !(*visited)[idx-1]) {
                    if ((*visited2)[idx-1]) return steps;
                    // if (idx-1 == n-1) return steps;
                    (*visited)[idx-1] = true;
                    (*q).push(idx-1);
                }
                if (map.count(arr[idx]) && map[arr[idx]].size() > 1) {
                    auto& vi = map[arr[idx]];
                    for (int j: vi) {
                        if (!(*visited)[j]) {
                            if ((*visited2)[j]) return steps;
                            // if (j == n-1) return steps;
                            (*visited)[j] = true;
                            (*q).push(j);
                        }
                    }
                    vi.clear();
                }
            }
        }
        return steps;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};
    cout<<s.minJumps(arr)<<endl; // 3
    return 0;
}
