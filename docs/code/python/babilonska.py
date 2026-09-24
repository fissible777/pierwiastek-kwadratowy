"""Metoda babilonska (metoda Herona) obliczania pierwiastka kwadratowego."""
import math


def pierwiastek_babilonski(s: float, eps: float = 1e-15) -> float:
    """Oblicza sqrt(s) metoda babilonska z zadana dokladnoscia."""
    if s < 0:
        raise ValueError("Liczba pod pierwiastkiem nie moze byc ujemna")
    if s == 0:
        return 0.0

    x = s
    while True:
        poprzednie = x
        x = 0.5 * (x + s / x)
        if abs(x - poprzednie) <= eps:
            return x


if __name__ == "__main__":
    for liczba in (2, 10, 144, 1000, 999999):
        wynik = pierwiastek_babilonski(liczba)
        wzorcowy = math.sqrt(liczba)
        print(f"sqrt({liczba})")
        print(f"  metoda babilonska : {wynik:.15f}")
        print(f"  math.sqrt         : {wzorcowy:.15f}")
        print(f"  roznica           : {abs(wynik - wzorcowy):.15f}\n")
