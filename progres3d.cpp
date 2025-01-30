#include <iostream>
#include <vector>
#include <cmath>
#include "matplotlibcpp.h"

using namespace std;
namespace plt = matplotlibcpp;

double compute_z(double x, double y, double a, double b, double c, double d) {
    return a * x + b * y + (c * pow(x, 2) + d * pow(y, 2));
}

int main() {
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

    // Menambahkan label pada sumbu
    plt::xlabel("Sumbu X");
    plt::ylabel("Sumbu Y");

    plt::show();

    return 0;
}