"""Eksperyment (wersja Python, dodatkowa): sqrt() vs metoda babilonska.
Zakres 1..1_000_000, 5 powtorzen. Wynik zapisywany do CSV.
Uruchomienie: python3 eksperyment.py > ../../experiment/wyniki_python.csv
"""
import math
import time
import sys

N = 1_000_000
POWTORZENIA = 5
EPS = 1e-15


def pierwiastek_babilonski(s, eps=EPS):
    if s <= 0:
        return 0.0
    x = s
    while True:
        poprzednie = x
        x = 0.5 * (x + s / x)
        if abs(x - poprzednie) <= eps:
            return x


def main():
    print("proba,sqrt_s,babilonska_s")
    for proba in range(1, POWTORZENIA + 1):
        start = time.perf_counter()
        suma1 = sum(math.sqrt(i) for i in range(1, N + 1))
        czas_sqrt = time.perf_counter() - start

        start = time.perf_counter()
        suma2 = sum(pierwiastek_babilonski(i) for i in range(1, N + 1))
        czas_bab = time.perf_counter() - start

        print(f"{proba},{czas_sqrt:.6f},{czas_bab:.6f}")
        print(
            f"Proba {proba}: sqrt={czas_sqrt:.6f}s  babilonska={czas_bab:.6f}s "
            f"(suma kontrolna: {suma1:.3f} / {suma2:.3f})",
            file=sys.stderr,
        )


if __name__ == "__main__":
    main()
