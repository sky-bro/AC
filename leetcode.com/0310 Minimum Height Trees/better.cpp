#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
    private:
        vector<int> result;
        char equal = 0;
    public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (edges.empty()) {
            return {0};
        }
        
        // build adjacent lists
        vector<pair<int, int>> graph(n);
        for (const vector<int>& edge: edges) {
            graph[edge[0]].first++;
            graph[edge[0]].second += edge[1];
            graph[edge[1]].first++;
            graph[edge[1]].second += edge[0];
        }
        
        // collect leafs
        vector<int> next;
        for (int i = 0; i < n; ++i) {
            if (graph[i].first == 1) {
                next.emplace_back(i);
            }
        }
        if (n == next.size()) {
            return next;
        }
        
        // find the highest level nodes
        int begin(0), end(next.size());
        int count(next.size());
        while (true) {
            for (int i = begin; i < end; ++i) {
                int neighbor = graph[next[i]].second;
                graph[neighbor].second -= next[i];
                if (--graph[neighbor].first==1) {
                    next.push_back(neighbor);
                    count++;
                }
            }
            if (n == count) {
                break;
            }
            begin = end;
            end = next.size();
        }
        next.erase(next.begin(),next.begin() + end);
        return next;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> edges = {{1,0},{1,2},{1,3}};
    s.findMinHeightTrees(4, edges);
    return 0;
}
