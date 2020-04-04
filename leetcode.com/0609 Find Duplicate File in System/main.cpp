#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> findDuplicate(vector<string> &infos) {
    unordered_map<string, vector<string>> content2path;
    for (string &info : infos) {
      istringstream ISS(info);
      string folder;
      ISS >> folder;
      folder.push_back('/');
      string fileanme_content;
      while (ISS >> fileanme_content) {
        int pos = fileanme_content.find('(');
        string path = folder + fileanme_content.substr(0, pos);
        string content = fileanme_content.substr(pos);
        content2path[content].push_back(path);
      }
    }

    vector<vector<string>> res;
    for (auto &p : content2path) {
      if (p.second.size() > 1) {
        res.push_back(p.second);
      }
    }
    return res;
  }
};

template <typename T>
void printArr(const vector<T> &arr) {
  for (const T &t : arr) cout << t << " ";
  cout << endl;
}

template <typename T>
void printArr2D(const vector<vector<T>> &arr2D) {
  for (const auto &vt : arr2D) printArr(vt);
}

int main(int argc, char const *argv[]) {
  Solution s;
  vector<string> infos = {"root/a 1.txt(abcd) 2.txt(efgh)",
                          "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)",
                          "root 4.txt(efgh)"};
  printArr2D(s.findDuplicate(infos));
  return 0;
}
