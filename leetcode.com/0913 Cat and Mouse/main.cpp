#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

struct Node
{
    int m, c;
    bool MTurn, MWin;
    Node(int m, int c, bool MTurn, bool MWin): m(m), c(c), MTurn(MTurn), MWin(MWin) {}
};


class Solution {
private:
    const bool MWin = true;
    // const bool CWin = false;
    const bool MTurn = true;
    // const bool CTurn = false;
public:

    /**
     * mouse start at node 1
     * cat start at node 2
     * @returns 1 if mouse wins, 2 if cat wins, 0 if draw
     */
    int catMouseGame(vector<vector<int>>& graph) {
        // node: (m, c, t, result) -- mouse position, cat position, current turn, result: mwin/cwin (no draw in queue)
        // intial win or lose:
        //  mouse: mouse at hole (0)
        //  cat  : cat over mouse
        // pop a node:
        //  MTurn: this is mouse's turn, we now decide the result of the previous step -- cat's turn
        //      mwin: mouse wins at current step
        //          cat's choice -1 -- cat cannot go to this position, or mwin
        //          0 choice left: mwin
        //      cwin: cat wins at current step
        //          in previous step -- cat's turn, cat must cat win if it chooses this position to go
        //  CTurn: this is cat's turn, we now decide the result of the previous step -- mouse's turn
        //      mwin: mouse wins at current step
        //          mouse must can win
        //      cwin:
        //          mouse's choice -1 -- mouse cannot go to this node, or cwin
        //          0 choice left: cwin
        // push this node if we have decided win/lose (not draw)
        int n = graph.size();
        queue<Node> q;
        vector<vector<array<int, 2>>> choices(n, vector<array<int, 2>>(n));
        vector<vector<array<int,2>>> results(n, vector<array<int,2>>(n, {2,2})); // results[MPosition][CPosition][1: MTurn, 0: CTurn] = 1: MWin / 0: CWIN / 2: Draw
        // init
        for (int m = 0; m < n; ++m) {
            for (int c = 1; c < n; ++c) {
                if (c && !m) { // MWin
                    results[0][c][MTurn] = results[0][c][!MTurn] = MWin;
                    q.emplace(m, c, MTurn, MWin);
                    q.emplace(m, c, !MTurn, MWin);
                } else if (m == c) { // CWin
                    results[m][c][MTurn] = results[m][c][!MTurn] = !MWin;
                    q.emplace(m, c, MTurn, !MWin);
                    q.emplace(m, c, !MTurn, !MWin);
                }
                choices[m][c][MTurn] = graph[m].size();
                choices[m][c][!MTurn] = graph[c].size() - (find(graph[c].begin(), graph[c].end(), 0) != graph[c].end());
            }
        }
        while (!q.empty()) {
            Node p = q.front();
            q.pop();
            if (p.MTurn) { // last step was took by cat
                for (int pc: graph[p.c]) { // previous cat postion
                    if (!pc) continue;
                    if (results[p.m][pc][!MTurn] != 2) continue;
                    if (p.MWin) { // MWin
                        if (--choices[p.m][pc][!MTurn] == 0) results[p.m][pc][!MTurn] = MWin;
                    } else { // CWin
                        results[p.m][pc][!MTurn] = !MWin;
                    }
                    if (results[p.m][pc][!MTurn] != 2) q.emplace(p.m, pc, !MTurn, results[p.m][pc][!MTurn]);
                }
            } else { // last step was took by mouse
                for (int pm: graph[p.m]) { // previous mouse position
                    if (results[pm][p.c][MTurn] != 2) continue;
                    if (p.MWin) {
                        results[pm][p.c][MTurn] = MWin;
                    } else {
                        if (--choices[pm][p.c][MTurn] == 0) results[pm][p.c][MTurn] = !MWin;
                    }
                    if (results[pm][p.c][MTurn] != 2) q.emplace(pm, p.c, MTurn, results[pm][p.c][MTurn]);
                }
            }
        }
        // 1 2 0
        // 1 0 2
        return (results[1][2][MTurn] & 1) ? 1 : (results[1][2][MTurn] ^ 2);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> g = {{2,3},{3,4},{0,4},{0,1},{1,2}};
    cout << s.catMouseGame(g) << endl;
    return 0;
}

