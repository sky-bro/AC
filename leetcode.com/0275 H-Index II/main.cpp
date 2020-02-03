#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), h = n;
        if (n == 0 || citations[n-1] == 0) return 0;
        for (; citations[n-h] < h; --h);
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
