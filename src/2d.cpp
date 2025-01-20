#include <matplotlibcpp.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <limits>

namespace plt = matplotlibcpp;

int main() {
    // Menampilkan pilihan rumus untuk pengguna
    std::cout << "Pilih rumus untuk digambar:\n";
    std::cout << "1. y = x^2\n";
    std::cout << "2. y = 2x + 1\n";
    std::cout << "3. y = sin(x)\n";
    std::cout << "Masukkan pilihan (1/2/3): ";
    
    int pilihan;
    std::cin >> pilihan;  // Input dari pengguna untuk memilih rumus

    // Membuat rentang nilai x
    std::vector<double> x;
    for (double i = -10; i <= 10; i += 0.1) {
        x.push_back(i);
    }

    // Vektor untuk menyimpan nilai y
    std::vector<double> y;

    // Variabel untuk mencari nilai maksimum dan minimum dari y
    double y_min = std::numeric_limits<double>::max();
    double y_max = std::numeric_limits<double>::lowest();

    // Pilih rumus berdasarkan input pengguna
    switch (pilihan) {
        case 1:
            // Rumus y = x^2
            for (double xi : x) {
                double yi = xi * xi;
                y.push_back(yi);
                if (yi < y_min) y_min = yi;
                if (yi > y_max) y_max = yi;
            }
            plt::title("Grafik y = x^2");
            break;
        case 2:
            // Rumus y = 2x + 1
            for (double xi : x) {
                double yi = 2 * xi + 1;
                y.push_back(yi);
                if (yi < y_min) y_min = yi;
                if (yi > y_max) y_max = yi;
            }
            plt::title("Grafik y = 2x + 1");
            break;
        case 3:
            // Rumus y = sin(x)
            for (double xi : x) {
                double yi = sin(xi);
                y.push_back(yi);
                if (yi < y_min) y_min = yi;
                if (yi > y_max) y_max = yi;
            }
            plt::title("Grafik y = sin(x)");
            break;
        default:
            std::cout << "Pilihan tidak valid!" << std::endl;
            return 1;
    }

    // Membuat diagram kartesius
    plt::plot(x, y);

    // Menambahkan garis sumbu X dan Y dengan panjang yang sesuai dengan grafik
    std::vector<double> x_axis = {-10, 10};  // Rentang sumbu X
    std::vector<double> y_axis = {0, 0};     // Sumbu X (y = 0)
    plt::plot(x_axis, y_axis, "k-");  // Garis sumbu X (warna hitam)

    std::vector<double> x_axis_vert = {0, 0};  // Sumbu Y (x = 0)
    std::vector<double> y_axis_vert = {y_min, y_max};  // Rentang sumbu Y sesuai grafik
    plt::plot(x_axis_vert, y_axis_vert, "k-");  // Garis sumbu Y (warna hitam)

    // Menambahkan grid untuk mempermudah pembacaan grafik
    plt::grid(true);

    // Menambahkan label pada sumbu X dan Y
    plt::xlabel("X Axis");
    plt::ylabel("Y Axis");

    // Menampilkan plot
    plt::show();

    return 0;
}
