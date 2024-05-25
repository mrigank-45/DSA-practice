#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        double minuteAngle = 6 * minutes;             
        double hourAngle = 30 * hour + 0.5 * minutes; 

        double angle = abs(minuteAngle - hourAngle);
        return min(angle, 360 - angle); 
    }
};
