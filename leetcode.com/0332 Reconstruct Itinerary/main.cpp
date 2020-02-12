#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

// ref: https://leetcode.com/problems/reconstruct-itinerary/discuss/78768/Short-Ruby-Python-Java-C%2B%2B
class Solution {
private:
    vector<string> result;
    unordered_map<string, multiset<string>> map;
    void dfs(const string &next) {
        while (map[next].size()) {
            string str = *map[next].begin();
            map[next].erase(map[next].begin());
            dfs(str);
        }
        result.push_back(next);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        result.clear();
        map.clear();
        for (auto &vs: tickets) {
            map[vs[0]].insert(vs[1]);
        }
        string next = "JFK";
        dfs(next);
        return vector<string>(result.rbegin(), result.rend());
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<string>> tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    // s.findItinerary(tickets);

    tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    // s.findItinerary(tickets);

    tickets = {{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}};
    s.findItinerary(tickets); //["JFK","ANU","EZE","AXA","TIA","ANU","JFK","TIA","ANU","TIA","JFK"]
    return 0;
}
