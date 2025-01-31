#include "matplotlibcpp.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>

using namespace std;
namespace plt = matplotlibcpp;

int main() {
    cout << "===== KALKULUS 2D =====\n\n";
    cout << "=== Fungsi y = f(x) ===\n";
    cout << "1. y = x^2\n";
    cout << "2. y = 2x + 1\n";
    cout << "3. y = sin(x)\n";
    cout << "4. y = cos(x)\n";
    cout << "5. y = tan(x)\n\n";
    cout << "=== Fungsi y^2 = f(x) ===\n";
    cout << "6. y^2 = x \n";
    cout << "7. y^2 = x^2\n\n";
    cout << "Masukkan pilihan (1-7) : ";
    
    int pilihan;
    cin >> pilihan;

    // Vector untuk menyimpan koordinat
    vector<double> x1, y1;  // Untuk kurva pertama/utama
    vector<double> x2, y2;  // Untuk kurva kedua (jika diperlukan)
    
    double start = -10, end = 10, step = 0.05;
    double y_min = numeric_limits<double>::max();
    double y_max = numeric_limits<double>::lowest();
    
    string title;

    if (pilihan <= 5) {
        // Membuat rentang x
        for (double i = start; i <= end; i += step) {
            x1.push_back(i);
        }
    }

    switch (pilihan) {
        case 1: {
            for (double xi : x1) {
                double yi = xi * xi;
                y1.push_back(yi);
                if (yi < y_min) y_min = yi;
                if (yi > y_max) y_max = yi;
            }
            title = "y = x^2";
            break;
        }
        case 2: {
            for (double xi : x1) {
                double yi = 2 * xi + 1;
                y1.push_back(yi);
                if (yi < y_min) y_min = yi;
                if (yi > y_max) y_max = yi;
            }
            title = "y = 2x + 1";
            break;
        }
        case 3: {
            for (double xi : x1) {
                double yi = sin(xi);
                y1.push_back(yi);
                if (yi < y_min) y_min = yi;
                if (yi > y_max) y_max = yi;
            }
            title = "y = sin(x)";
            break;
        }
        case 4: {
            for (double xi : x1) {
                double yi = cos(xi);
                y1.push_back(yi);
                if (yi < y_min) y_min = yi;
                if (yi > y_max) y_max = yi;
            }
            title = "y = cos(x)";
            break;
        }
        case 5: {
            for (double xi : x1) {
                double yi = tan(xi);
                if (yi > 10) yi = 10;     // Membatasi nilai tan
                if (yi < -10) yi = -10;   
                y1.push_back(yi);
                if (yi < y_min) y_min = yi;
                if (yi > y_max) y_max = yi;
            }
            title = "y = tan(x)";
            break;
        }
        
        case 6: {
            // y^2 = x 
            for (double x = 0; x <= end; x += step) {
                double y = sqrt(x);
                x1.push_back(x);
                y1.push_back(y);
                x2.push_back(x);
                y2.push_back(-y);
                if (abs(y) > y_max) y_max = abs(y);
                if (-abs(y) < y_min) y_min = -abs(y);
            }
            title = "y^2 = x";
            break;
        }
        case 7: {
            // y^2 = x^2 
            for (double x = start; x <= end; x += step) {
                double y = abs(x);
                x1.push_back(x);
                y1.push_back(y);
                x2.push_back(x);
                y2.push_back(-y);
                if (abs(y) > y_max) y_max = abs(y);
                if (-abs(y) < y_min) y_min = -abs(y);
            }
            title = "y^2 = x^2";
            break;
        }
        default:
            cout << "Pilihan tidak valid!" << endl;
            return 1;
    }

    map<string, string> keywords1, keywords2;
    keywords1["color"] = "blue";
    keywords1["label"] = title;
    keywords2["color"] = "blue";
    keywords2["label"] = "";  // Label kosong untuk fungsi y^2 biar ga double labelnya

    plt::plot(x1, y1, keywords1);
    if (!x2.empty() && !y2.empty()) {  // Jika ada kurva kedua
        plt::plot(x2, y2, keywords2);  // Menggunakan keywords2 tanpa label
    }

    // Menambahkan garis sumbu
    vector<double> x_axis = {start, end};
    vector<double> y_axis = {0, 0};
    plt::plot(x_axis, y_axis, "k--");

    vector<double> x_axis_vert = {0, 0};
    vector<double> y_axis_vert = {y_min - 1, y_max + 1};
    plt::plot(x_axis_vert, y_axis_vert, "k--");

    plt::grid(true);
    plt::legend();

    double y_margin = (y_max - y_min) * 0.1;
    plt::ylim(y_min - y_margin, y_max + y_margin);

    plt::show();

    return 0;
}