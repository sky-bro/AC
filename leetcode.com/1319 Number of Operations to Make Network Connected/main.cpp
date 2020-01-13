#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    void dfs(int i, vector<bool> &visited, vector<unordered_set<int>> &graph) {
        if (graph[i].empty()) return;
        for (int next_i: graph[i]) {
            if (!visited[next_i]) {
                visited[next_i] = true;
                dfs(next_i, visited, graph);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if (m < n - 1) return -1;
        vector<bool> visited(n);
        vector<unordered_set<int>> graph(n);
        for (auto &edge: connections) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        int result = -1;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++result;
                visited[i] = true;
                dfs(i, visited, graph);
            }
        }
        return result;
    }
};