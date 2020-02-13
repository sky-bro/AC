#include <iostream>
#include <vector>

using namespace std;

// naive, find pattern
class Solution0 {
public:
    vector<int> countBits(int num) {
        // num = 16
        // 0 1 1 2 1 2 2 3 1 2 2 3 2 3 3 4 1
        vector<int> res;
        for (int i = 0; i <= num; ++i) {
            res.push_back(__builtin_popcount(i));
        }
        return res;
    }
};

class Solution {
public:
    vector<int> countBits(int num) {
        // num = 16
        // 0 1 1 2 1 2 2 3 1 2 2 3 2 3 3 4 1
        vector<int> res{0};
        for (int r = 1; r <= num; r <<= 1) {
            for (int i = 0; i + r <= num  && i < r; ++i) {
                res.push_back(res[i] + 1);
            }
        }
        return res;
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
