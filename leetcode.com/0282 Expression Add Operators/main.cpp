#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class Solution {
private:
    vector<string> result;
    ll target;
    int n;

    void dfs(const string &num, int start, ll prev_sum, ll cur_num, string &path) {
        if (start == n) {
            if (prev_sum + cur_num == target) {
                cout<<path<<endl;
                result.push_back(path);
            }
            return;
        }

        for (int len = 1; start + len <= n; ++len) {
            string i_str = num.substr(start, len);
            if (i_str[0] == '0' && len > 1) continue;
            ll i = stoll(i_str);

            if (start == 0) {
                path.append(i_str);
                dfs(num, start+len, 0, i, path);
                path.erase(0);
                continue;
            }

            path.push_back('+');
            path.append(i_str);
            dfs(num, start+len, prev_sum + cur_num, i, path);
            path.erase(path.length() - (1 + len));

            path.push_back('-');
            path.append(i_str);
            dfs(num, start+len, prev_sum + cur_num, -i, path);
            path.erase(path.length() - (1 + len));

            path.push_back('*');
            path.append(i_str);
            dfs(num, start+len, prev_sum, cur_num * i, path);
            path.erase(path.length() - (1 + len));
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        this->target = target;
        this->n = num.size();
        string path = "";
        dfs(num, 0, 0, 0, path);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    string str;
    int target;
    while (cin>>str>>target) {
        Solution s;
        s.addOperators(str, target);
    }
    return 0;
}
