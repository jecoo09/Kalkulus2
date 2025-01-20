#include <iostream>
// #include "matplotlibcpp.h"
#include "C:/test3d/include/matplotlibcpp.h"
#include <vector>
#include <cmath>

namespace plt = matplotlibcpp;

int main() {
    // Membuat data sederhana
    std::vector<double> x, y;
    
    // Generate data points untuk kurva 2D sederhana
    for(int i = 0; i < 1000; i++) {
        double t = i * 2 * M_PI / 999;
        x.push_back(t);
        y.push_back(sin(t));
    }

    // Plot kurva 2D
    plt::plot(x, y);
    
    // Set labels
    plt::xlabel("x");
    plt::ylabel("y");
    
    // Set title
    plt::title("Simple Plot Test");
    
    // Show plot
    plt::show();

    return 0;
}