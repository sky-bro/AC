#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    vector<int> *prestaurants;
    Node(vector<int> *_prestaurants): prestaurants(_prestaurants) {}
};

bool cmp(const Node &a, const Node &b) {
    vector<int> &restaurant_a = *a.prestaurants;
    vector<int> &restaurant_b = *b.prestaurants;
    if (restaurant_a[1] == restaurant_b[1]) return restaurant_a[0] > restaurant_b[0];
    return restaurant_a[1] > restaurant_b[1];
}

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> result;
        vector<Node> arr;
        for (auto &restaurant: restaurants) {
            if (veganFriendly && !restaurant[2]) continue;
            if (restaurant[3] > maxPrice) continue;
            if (restaurant[4] > maxDistance) continue;
            arr.push_back(Node(&restaurant));
        }
        sort(arr.begin(), arr.end(), cmp);
        for (Node &node: arr) {
            result.push_back((*node.prestaurants)[0]);
        }
        return result;
    }
};