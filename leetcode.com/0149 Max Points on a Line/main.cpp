#include <iostream>
#include <vector>
// #include <unordered_map>
// #include <boost/functional/hash.hpp>
#include <map>
#include <algorithm>

using namespace std;

typedef std::pair<int, int> int_pair;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;
        // unordered_map<int_pair, int, boost::hash<int_pair> > gradients;
        map<int_pair, int> gradients;
        for (int i = 0; i < n - result; ++i) {
            gradients.clear();
            int over = 1, vertical = 0, cur_max = 0;
            for (int j = i+1; j < n; ++j) {
                if (points[i][0] == points[j][0]) {
                    if (points[i][1] == points[j][1]) over++;
                    else if (++vertical > cur_max) cur_max = vertical;
                    continue;
                }
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                int div = __gcd(dy, dx);
                int_pair i_pair = {dy / div, dx / div};
                if (++gradients[i_pair] > cur_max) {
                    cur_max = gradients[i_pair];
                }
            }
            result = max(result, cur_max + over);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> points = {{84,250},{0,0},{1,0},{0,-70},{0,-70},{1,-1},{21,10},{42,90},{-42,-230}};
    vector<vector<int>> points2 = {{0,0},{94911151,94911150},{94911152,94911151}};
    Solution s;
    cout<<s.maxPoints(points2)<<endl;
    return 0;
}

