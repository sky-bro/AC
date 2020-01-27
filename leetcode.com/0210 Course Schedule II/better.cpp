#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {

    enum class state{white, grey, black};
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adjList(numCourses); //check init for inner vector
        deque<int> res;
        
        for(auto& edge:prerequisites)
        {
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<state> visited(numCourses, state::white);
        
        for(auto i=0; i<numCourses;++i)
        {
            if(visited[i] == state::white)            
            {
                if(dfs(adjList, i, visited, res))
                    return vector<int>();
            }
        }

       vector<int> result (res.begin(), res.end()); 
       return result;         
    }
    
    bool dfs ( const vector<vector<int>>& adjList, int node,  vector<state>& visited, deque<int>& res)
    {
        if(visited[node] == state::grey)
                return true;
        
        visited[node] = state::grey;
        
        for(auto i =0;i<adjList[node].size(); ++i)
        {   
            if(visited[adjList[node][i]] != state::black)
            {
                if(dfs(adjList, adjList[node][i], visited, res))
                    return true;
            }
        }
        
        visited[node] = state::black;
        res.push_front(node);
        return false;
    }
};