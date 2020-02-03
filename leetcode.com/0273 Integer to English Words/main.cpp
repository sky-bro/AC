#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> num_str = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> num_str_teen = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> num_str_ty = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<int> bases = {1, 1000, 1000000, 1000000000};
    vector<string> bases_str = {"", "Thousand", "Million", "Billion"};

    string read_chunk(int num_3digits) {
        string result = "";
        if (num_3digits / 100) {
            result += num_str[num_3digits/100] + " Hundred";
            num_3digits %= 100;
            if (num_3digits) result.push_back(' ');
            else return result;
        }

        switch (num_3digits / 10)
        {
        case 0:
            result += num_str[num_3digits];
            break;
        case 1:
            result += num_str_teen[num_3digits-10];
            break;
        default:
            result += num_str_ty[num_3digits / 10];
            num_3digits %= 10;
            if (num_3digits) {
                result.push_back(' ');
                result += num_str[num_3digits];
            }
            break;
        }
        return result;
    }
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string result = "";
        for (int i = 3; i >= 0; --i) {
            int chunk = num / bases[i];
            if (chunk) {
                result += read_chunk(chunk);
                if (bases[i] != 1) {
                    result.push_back(' ');
                    result += bases_str[i];
                }
                num %= bases[i];
                if (num) result.push_back(' ');
                else break;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    int num;
    Solution s;
    while (cin>>num) {
        cout<<s.numberToWords(num)<<endl;
    }
    return 0;
}
