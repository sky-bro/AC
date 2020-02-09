#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int val;
    int cnt;
    Node(int _val, int _cnt): val(_val), cnt(_cnt) {}
};


class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        if (n < k) return 0;
        int l = 0, r = k-1;
        threshold *= k;
        int cur_sum = 0;
        for (int i = 0; i < k; ++i) {
            cur_sum += arr[i];
        }
        int result = cur_sum >= threshold;
        for (++l, ++r; r < n; ++l, ++r) {
            cur_sum += arr[r] - arr[l-1];
            if (cur_sum >= threshold) ++result;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> arr = {11,13,17,23,29,31,7,5,2,3};
    int k = 3, threshold = 5;
    cout<<s.numOfSubarrays(arr, k, threshold)<<endl;
    return 0;
}
