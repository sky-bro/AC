#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num+1, 0);
        for (int i = 1; i<= num; i++)
        {
            v[i] = v[i>>1] + (i&1);
        }
        return v;
    }
};

void printArr(vector<int> arr) {
    for (int num: arr) {
        cout<<num<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    Solution s;
    int num;
    while (cin>>num) {
        printArr(s.countBits(num));
    }
    return 0;
}
