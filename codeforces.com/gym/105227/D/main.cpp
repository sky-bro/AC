#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<string> names;
    while (n--) {
        string name;
        cin >> name;
        names.push_back(name);
    }
    unordered_set<string> visited;
    while (!names.empty()) {
        string name = names.back();
        names.pop_back();
        if (visited.find(name) == visited.end()) {
            visited.insert(name);
            cout << name << endl;
        }
    }
    return 0;
}
