#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Cashier {
 private:
  int idx;
  int n;
  double discount;
  unordered_map<int, int> id2prices;

 public:
  Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
    idx = 0;
    this->n = n;
    for (int i = 0; i < products.size(); ++i) {
      id2prices[products[i]] = prices[i];
    }
    this->discount = 1 - discount / 100.0;
  }

  double getBill(vector<int> product, vector<int> amount) {
    ++idx;
    double res = 0;
    for (int i = 0; i < product.size(); ++i) {
      res += id2prices[product[i]] * amount[i];
    }
    if (idx == n) {
      res *= discount;
      idx = 0;
    }
    return res;
  }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */