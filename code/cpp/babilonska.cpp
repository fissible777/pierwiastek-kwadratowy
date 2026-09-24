// Metoda babilonska (metoda Herona) obliczania pierwiastka kwadratowego.
// Kompilacja: g++ -O2 -std=c++17 babilonska.cpp -o babilonska
#include <iostream>
#include <cmath>
#include <iomanip>

// Oblicza sqrt(S) metoda babilonska z zadana dokladnoscia (domyslnie 1e-15).
double pierwiastekBabilonski(double S, double eps = 1e-15) {
    if (S < 0) return NAN;
    if (S == 0) return 0.0;

    double x = S;                 // przyblizenie poczatkowe
    double poprzednie;

    do {
        poprzednie = x;
        x = 0.5 * (x + S / x);    // wzor iteracyjny Herona
    } while (std::fabs(x - poprzednie) > eps);

    return x;
}

int main() {
    double liczby[] = {2.0, 10.0, 144.0, 1000.0, 999999.0};

    std::cout << std::fixed << std::setprecision(15);
    for (double S : liczby) {
        double wynik = pierwiastekBabilonski(S);
        double wzorcowy = std::sqrt(S);
        std::cout << "sqrt(" << S << ")\n"
                  << "  metoda babilonska : " << wynik << "\n"
                  << "  std::sqrt         : " << wzorcowy << "\n"
                  << "  roznica           : " << std::fabs(wynik - wzorcowy) << "\n\n";
    }
    return 0;
}
