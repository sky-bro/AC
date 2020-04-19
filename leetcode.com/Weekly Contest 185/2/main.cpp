#include <bits/stdc++.h>

#include <map>
#include <set>
using namespace std;

class Solution {
 public:
  vector<vector<string>> displayTable(vector<vector<string>> &orders) {
    set<string> dishes;
    map<int, unordered_map<string, int>> tables;
    for (auto &order : orders) {
      int id = stoi(order[1]);
      string dish = order[2];
      dishes.insert(dish);
      tables[id][dish]++;
    }

    vector<vector<string>> res;
    vector<string> head;
    head.push_back("Table");
    for (auto &dish : dishes) head.push_back(dish);
    res.push_back(head);
    for (auto &table : tables) {
      vector<string> row;
      row.push_back(to_string(table.first));
      for (auto &dish : dishes) {
        auto it = table.second.find(dish);
        if (it == table.second.end())
          row.push_back("0");
        else
          row.push_back(to_string(it->second));
      }
      res.push_back(row);
    }
    return res;
  }
};