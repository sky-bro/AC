#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        else if (n == 2) return {0, 1};
        unordered_map<int, int> degrees;
        set<pair<int, int>> edges_set;
        
        for (auto edge: edges) {
            degrees[edge[0]]++;
            degrees[edge[1]]++;
            edges_set.insert(make_pair(edge[0], edge[1]));
        }

        int remain_cnt = n;
        while (remain_cnt != 1 && remain_cnt != 2) {
            vector<int> nodes_to_remove;
            for (auto it = degrees.begin(); it != degrees.end();) {
                if (it->second == 1) {
                    nodes_to_remove.push_back(it->first);
                    degrees.erase(it++);
                } else {
                    ++it;
                }
            }
            remain_cnt -= nodes_to_remove.size();
            while (!nodes_to_remove.empty()) {
                int node_to_remove = nodes_to_remove.back(); nodes_to_remove.pop_back();
                for (auto it = edges_set.begin(); it != edges_set.end();) {
                    if (it->first == node_to_remove) {
                        degrees[it->second]--;
                        edges_set.erase(it++);
                        break;
                    } else if (it->second == node_to_remove) {
                        degrees[it->first]--;
                        edges_set.erase(it++);
                        break;
                    } else {
                        ++it;
                    }
                }
            }
        }
        vector<int> result;
        for (auto it = degrees.begin(); it != degrees.end(); ++it) {
            result.push_back(it->first);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> edges = {{1,0},{1,2},{1,3}};
    s.findMinHeightTrees(4, edges);
    return 0;
}
