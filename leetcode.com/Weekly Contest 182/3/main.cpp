#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class UndergroundSystem {
 private:
  unordered_map<int, pair<string, int>> mp1;
  map<pair<string, string>, pair<int, int>> mp2;

 public:
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    mp1.emplace(id, make_pair(stationName, t));
  }

  void checkOut(int id, string stationName, int t) {
    auto p1 = mp1[id];
    auto id2 = make_pair(p1.first, stationName);
    auto p2 = mp2[id2];
    mp2[id2] = make_pair(p2.first + 1, p2.second + t - p1.second);
    mp1.erase(id);
  }

  double getAverageTime(string startStation, string endStation) {
    auto p = mp2[make_pair(startStation, endStation)];
    return double(p.second) / p.first;
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */