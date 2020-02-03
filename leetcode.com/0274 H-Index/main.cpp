#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int h = citations.size();
        if (h == 0 || citations[0] == 0) return 0;
        for (; citations[h-1] < h; --h);
        return h;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> citations = {3,0,6,1,5};
    Solution s;
    cout<<s.hIndex(citations)<<endl;
    return 0;
}
