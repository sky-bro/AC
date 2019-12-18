/*
A topological ordering is possible if and only if the graph has no directed cycles, that is, 
if it is a directed acyclic graph (DAG). 
Any DAG has at least one topological ordering, 
and algorithms are known for constructing a topological ordering of any DAG in linear time.
*/

// https://en.wikipedia.org/wiki/Topological_sorting
// 1. Kahn's algorithm
// 2. DFS

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    bool visit(int i, vector<int> &visited, vector<vector<int>>& prerequisites) {
        if (visited[i] == 1) return false;
        if (visited[i] == 2) return true;
        visited[i] = 1;
        for (auto &edge: prerequisites) {
            if (edge[0] == i) 
                if (!visit(edge[1], visited, prerequisites))
                    return false;
        }
        visited[i] = 2;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i])
                if (!visit(i, visited, prerequisites))
                    return false;
        }
        return true;
    }
};