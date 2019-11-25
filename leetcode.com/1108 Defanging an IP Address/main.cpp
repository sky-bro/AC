#include <iostream>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        char buf[0x18];
        int a, b, c, d;
        sscanf(address.c_str(), "%d.%d.%d.%d", &a, &b, &c, &d);
        sprintf(buf, "%d[.]%d[.]%d[.]%d", a, b, c, d);
        return string(buf);
    }

    // string defangIPaddr(string address) {
        
    //     string result = "";
    //     for (int i = 0; i < address.size(); i++){
    //         if (address[i] == '.'){
    //             result += "[.]";
    //         }
    //         else {
    //             result += address[i];
    //         }
    //     }
    //     return result;
    // }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.defangIPaddr("1.1.1.1")<<endl;
    cout<<s.defangIPaddr("255.100.50.0")<<endl;
    return 0;
}
