#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// use extra space
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n+1);
        for (int citation: citations) count[min(n, citation)]++;
        for (int sum = count[n]; sum < n; --n, sum += count[n]);
        return n;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> citations = {3,0,6,1,5};
    Solution s;
    cout<<s.hIndex(citations)<<endl;
    return 0;
}
