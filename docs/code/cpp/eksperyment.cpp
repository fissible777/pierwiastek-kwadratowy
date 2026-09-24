// Eksperyment: porownanie czasu obliczania pierwiastka kwadratowego
// funkcja biblioteczna std::sqrt()  vs  wlasna metoda babilonska (dokladnosc 1e-15)
// Zakres: liczby calkowite 1..1000000, 5 powtorzen calej serii.
//
// Kompilacja: g++ -O2 -std=c++17 eksperyment.cpp -o eksperyment
// Uruchomienie: ./eksperyment > ../../experiment/wyniki_cpp.csv

#include <iostream>
#include <cmath>
#include <chrono>
#include <iomanip>

constexpr long N = 1000000;
constexpr int POWTORZENIA = 5;
constexpr double EPS = 1e-15;

double pierwiastekBabilonski(double S, double eps = EPS) {
    if (S <= 0) return 0.0;
    double x = S, poprzednie;
    do {
        poprzednie = x;
        x = 0.5 * (x + S / x);
    } while (std::fabs(x - poprzednie) > eps);
    return x;
}

int main() {
    using namespace std::chrono;

    std::cerr << std::fixed << std::setprecision(6);
    std::cout << "proba,sqrt_s,babilonska_s\n";

    for (int proba = 1; proba <= POWTORZENIA; ++proba) {
        // std::sqrt
        volatile double suma1 = 0.0;
        auto t1 = high_resolution_clock::now();
        for (long i = 1; i <= N; ++i) {
            suma1 += std::sqrt(static_cast<double>(i));
        }
        auto t2 = high_resolution_clock::now();
        double czas_sqrt = duration<double>(t2 - t1).count();

        // metoda babilonska
        volatile double suma2 = 0.0;
        auto t3 = high_resolution_clock::now();
        for (long i = 1; i <= N; ++i) {
            suma2 += pierwiastekBabilonski(static_cast<double>(i));
        }
        auto t4 = high_resolution_clock::now();
        double czas_bab = duration<double>(t4 - t3).count();

        std::cout << proba << "," << std::setprecision(6) << czas_sqrt
                  << "," << czas_bab << "\n";
        std::cerr << "Proba " << proba << ": sqrt=" << czas_sqrt
                  << "s  babilonska=" << czas_bab << "s"
                  << "  (suma kontrolna: " << suma1 << " / " << suma2 << ")\n";
    }
    return 0;
}
