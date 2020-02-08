#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double degree_hour = hour * 30 + minutes * 0.5;
        if (degree_hour > 360) degree_hour -= 360;
        double degree_minutes = 6 * minutes;
        double result;
        if (degree_hour > degree_minutes) {
            result = degree_hour - degree_minutes;
        } else {
            result = degree_minutes - degree_hour;
        }
        return result > 180 ? 360 - result : result;
    }
};

int main(int argc, char const *argv[])
{
    int hour, minutes;
    Solution s;
    while (cin>>hour>>minutes) {
        cout<<s.angleClock(hour, minutes)<<endl;
    }
    return 0;
}
