// 478_在圆内随机生成点.cpp
#include "custom.h"
#include <random>
ustd

class Solution {
private:
    mt19937 gen{ random_device{}() };
    uniform_real_distribution<double> dis;
    const double PI = acos(-1.0);
    const double radius;
    const double x_center;
    const double y_center;
public:
    Solution(double radius, double x_center, double y_center)
        : dis(0, 1), radius(radius), x_center(x_center), y_center(y_center) { }

    vector<double> randPoint() {
        double phi = dis(gen) * 2 * PI;
        double rho = sqrt(dis(gen)) * radius; // 注意根号，点的密度和半径不成正比
        return { x_center + rho * cos(phi), y_center + rho * sin(phi) };
    }
};
