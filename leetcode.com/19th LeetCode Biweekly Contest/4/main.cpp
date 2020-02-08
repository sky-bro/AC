#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; ++i) {
            if (map.count(arr[i])) {
                map[arr[i]].push_back(i);
            } else {
                map[arr[i]] = {i};
            }
        }
        queue<int> q;
        queue<int> q2;
        q.push(0);
        q2.push(n-1);
        vector<bool> visited(n);
        vector<bool> visited2(n);
        visited[0] = true;
        visited2[n-1] = true;
        int steps = 0;
        while (true) {
            ++steps;
            if (q2.size() < q.size()) {
                swap(q, q2);
                swap(visited, visited2);
            }
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int idx = q.front(); q.pop();
                if (idx+1 < n && !visited[idx+1]) {
                    if (visited2[idx+1]) return steps;
                    visited[idx+1] = true;
                    q.push(idx+1);
                }
                if (idx-1 >= 0 && !visited[idx-1]) {
                    if (visited2[idx-1]) return steps;
                    visited[idx-1] = true;
                    q.push(idx-1);
                }
                if (map.count(arr[idx]) && map[arr[idx]].size() > 1) {
                    auto& vi = map[arr[idx]];
                    for (int j: vi) {
                        if (!visited[j]) {
                            if (visited2[j]) return steps;
                            visited[j] = true;
                            q.push(j);
                        }
                    }
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
