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

// wrong code, implemented as sub sequence cnt

class Solution {
private:
    int threshold;
    int n;
    int result;
    void dfs(vector<Node>& node_arr, int idx, int k, int cur_sum, vector<Node> &path) {
        if (idx == n) {
            if (k == 0 && cur_sum >= threshold) ++result;
            return;
        }
        for (int i = 0; i <= k && i <= node_arr[idx].cnt; ++i) {
            path.push_back(Node(node_arr[idx].val, i));
            dfs(node_arr, idx+1, k-i, cur_sum + node_arr[idx].val * i, path);
            path.pop_back();
        }
    }
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        sort(arr.begin(), arr.end());
        arr.push_back(0);
        int n = arr.size(); int cnt = 1;
        vector<Node> node_arr;
        for (int i = 1; i <= n; ++i) {
            if (arr[i] != arr[i-1]) {
                node_arr.push_back(Node(arr[i-1], cnt));
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        this->n = node_arr.size();
        this->threshold = threshold * k;
        result = 0;
        // vector<vector<int>> dp(this->n, vector<int>(this->n, -1));
        vector<Node> path;
        dfs(node_arr, 0, k, 0, path);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> arr = {2,2,2,2,5,5,5,8};
    int k = 3, threshold = 4;
    cout<<s.numOfSubarrays(arr, k, threshold)<<endl;
    return 0;
}
