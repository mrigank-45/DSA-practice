#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double x_min, x_max, y_min, y_max;
    double radius;

    Solution(double radius, double x_center, double y_center)
    {
        x_min = x_center - radius;
        x_max = x_center + radius;
        y_min = y_center - radius;
        y_max = y_center + radius;
        this->radius = radius;
    }

    vector<double> randPoint()
    {
        while (true)
        {
            double x_value = x_min + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (x_max - x_min)));
            double y_value = y_min + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (y_max - y_min)));
            if (x_value * x_value + y_value * y_value <= (radius) * (radius))
            {
                return {x_value, y_value};
            }
        }
    }
};
