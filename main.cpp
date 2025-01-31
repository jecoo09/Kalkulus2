#include "matplotlibcpp.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>

using namespace std;
namespace plt = matplotlibcpp;

// Fungsi untuk menghitung z pada plot 3D
double compute_z(double x, double y, double a, double b, double c, double d) {
    return a * x + b * y + (c * pow(x, 2) + d * pow(y, 2));
}

int main() {
    while(true) {
        cout << "===== KALKULUS 2D & 3D =====\n\n";
        cout << "=== Fungsi y = f(x) ===\n";
        cout << "1. y = x^2\n";
        cout << "2. y = 2x + 1\n";
        cout << "3. y = sin(x)\n";
        cout << "4. y = cos(x)\n";
        cout << "5. y = tan(x)\n\n";
        cout << "=== Fungsi y^2 = f(x) ===\n";
        cout << "6. y^2 = x \n";
        cout << "7. y^2 = x^2\n\n";
        cout << "=== Fungsi 3D ===\n";
        cout << "8. z = ax + by + (cx^2 + dy^2)\n\n";
        cout << "9. Keluar\n\n";
        cout << "Masukkan pilihan (1-8) : ";
        
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
                    double yi = -(xi * xi);
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
            case 8: {
                double a, b, c, d;
                
                cout << "Masukkan nilai a: ";
                cin >> a;
                cout << "Masukkan nilai b: ";
                cin >> b;
                cout << "Masukkan nilai c: ";
                cin >> c;
                cout << "Masukkan nilai d: ";
                cin >> d;

                PyObject* ax = plt::chart(111);
                plt::Clear3DChart(ax);

                // Membuat grid data
                int n = 60;
                double t0 = -4.0, t1 = 4.0;
                double dT = (t1 - t0) / (n - 1);

                vector<vector<double>> x, y, z;
                vector<double> tx, ty, tz;

                double rx, ry;

                for (int i = 0; i < n; ++i) {
                    tx.clear();
                    ty.clear();
                    tz.clear();
                    rx = t0 + i * dT;
                    for (int j = 0; j < n; ++j) {
                        ry = t0 + j * dT;
                        tx.push_back(rx);
                        ty.push_back(ry);
                        tz.push_back(compute_z(rx, ry, a, b, c, d));
                    }
                    x.push_back(tx);
                    y.push_back(ty);
                    z.push_back(tz);
                }

                plt::surface3D(ax, x, y, z, "blue", 0.9);
                plt::xlabel("Sumbu X");
                plt::ylabel("Sumbu Y");
                title = "z = ax + by + (cx^2 + dy^2)";
                break;
            }
            case 9 : {
                cout << "Bye bye";
                return 0;
            }
            default:
                cout << "Pilihan tidak valid!" << endl;
        }

        if (pilihan <= 7) {
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
        }

        plt::show();
    }

    return 0;
}