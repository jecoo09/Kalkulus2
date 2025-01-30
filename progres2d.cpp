#include "matplotlibcpp.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>

namespace plt = matplotlibcpp;

int main() {
    // Menampilkan pilihan rumus untuk pengguna
    std::cout << "Pilih rumus untuk digambar:\n";
    std::cout << "1. y = x^2\n";
    std::cout << "2. y = 2x + 1\n";
    std::cout << "3. y = sin(x)\n";
    std::cout << "4. y = cos(x)\n";
    std::cout << "5. y = tan(x)\n";
    std::cout << "6. y = log(x)\n";
    std::cout << "Masukkan pilihan (1-6): ";
    
    int pilihan;
    std::cin >> pilihan;

    // Membuat rentang nilai x dengan resolusi yang lebih tinggi
    std::vector<double> x;
    double start = -10, end = 10, step = 0.05;
    for (double i = start; i <= end; i += step) {
        x.push_back(i);
    }

    std::vector<double> y;
    double y_min = std::numeric_limits<double>::max();
    double y_max = std::numeric_limits<double>::lowest();
    
    std::string title;

    // Pilih rumus berdasarkan input pengguna
    switch (pilihan) {
        case 1: {
            for (double xi : x) {
                double yi = xi * xi;
                y.push_back(yi);
                if (yi < y_min) y_min = yi;
                if (yi > y_max) y_max = yi;
            }
            title = "y = x^2";
            break;
        }
        case 2: {
            for (double xi : x) {
                double yi = 2 * xi + 1;
                y.push_back(yi);
                if (yi < y_min) y_min = yi;
                if (yi > y_max) y_max = yi;
            }
            title = "y = 2x + 1";
            break;
        }
        case 3: {
            for (double xi : x) {
                double yi = sin(xi);
                y.push_back(yi);
                if (yi < y_min) y_min = yi;
                if (yi > y_max) y_max = yi;
            }
            title = "y = sin(x)";
            break;
        }
        case 4: {
            for (double xi : x) {
                double yi = cos(xi);
                y.push_back(yi);
                if (yi < y_min) y_min = yi;
                if (yi > y_max) y_max = yi;
            }
            title = "y = cos(x)";
            break;
        }
        case 5: {
            for (double xi : x) {
                double yi = tan(xi);
                // Membatasi nilai tan untuk visualisasi yang lebih baik
                if (yi > 10) yi = 10;
                if (yi < -10) yi = -10;
                y.push_back(yi);
                if (yi < y_min) y_min = yi;
                if (yi > y_max) y_max = yi;
            }
            title = "y = tan(x)";
            break;
        }
        case 6: {
            std::vector<double> valid_x, valid_y;
            for (double xi : x) {
                if (xi > 0) {
                    double yi = log(xi);
                    valid_x.push_back(xi);
                    valid_y.push_back(yi);
                    if (yi < y_min) y_min = yi;
                    if (yi > y_max) y_max = yi;
                }
            }
            x = valid_x;
            y = valid_y;
            title = "y = log(x)";
            break;
        }
        default:
            std::cout << "Pilihan tidak valid!" << std::endl;
            return 1;
    }

    // Plot fungsi utama dengan warna biru
    std::map<std::string, std::string> keywords;
    keywords["color"] = "blue";
    keywords["label"] = title;
    plt::plot(x, y, keywords);

    // Menambahkan garis sumbu
    std::vector<double> x_axis = {start, end};
    std::vector<double> y_axis = {0, 0};
    plt::plot(x_axis, y_axis, "k--");

    std::vector<double> x_axis_vert = {0, 0};
    std::vector<double> y_axis_vert = {y_min, y_max};
    plt::plot(x_axis_vert, y_axis_vert, "k--");

    // Konfigurasi grid dan legend
    plt::grid(true);
    plt::legend();

    // Set batas sumbu y yang lebih baik
    double y_margin = (y_max - y_min) * 0.1;
    plt::ylim(y_min - y_margin, y_max + y_margin);

    // Menampilkan plot
    plt::show();

    return 0;
}