#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void split(const string& s,vector<string>& vs,const char flag = ' ') {
    vs.clear();
    istringstream iss(s);
    string temp;

    while (getline(iss, temp, flag)) {
        vs.push_back(temp);
    }
    return;
}

class Solution {
public:
    string simplifyPath(string path) {
        string result = "";
        vector<string> vs;
        vector<string> result_vs;
        split(path, vs, '/');
        int n = vs.size();
        for (int i = 1; i < n; ++i) {
            if (vs[i] == "" || vs[i] == ".") continue;
            if (vs[i] == "..") {
                if (!result_vs.empty()) 
                    result_vs.pop_back();
            }
            else result_vs.push_back(vs[i]);
        }
        for (auto &s: result_vs) {
            result.push_back('/');
            result += s;
        }
        return result.empty()?"/":result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string path;
    while (cin>>path)
        cout<<s.simplifyPath(path)<<endl;
    return 0;
}
