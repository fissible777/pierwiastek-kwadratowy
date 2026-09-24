# Pierwiastek kwadratowy — metoda babilońska

Projekt szkolny: numeryczne metody obliczania pierwiastka kwadratowego, ze szczególnym
uwzględnieniem metody babilońskiej (Herona), oraz eksperyment porównujący jej wydajność
z funkcją biblioteczną `sqrt()`.

## Struktura repozytorium

```
site/                   strona internetowa (jednostronicowa, z nawigacją sekcjową)
  index.html
  style.css
  assets/                wykresy (SVG) wygenerowane z wyników eksperymentu

code/
  cpp/
    babilonska.cpp        implementacja + demo (przykładowe wywołania)
    eksperyment.cpp        program pomiarowy (5 x 1 000 000 obliczeń)
  python/
    babilonska.py          implementacja + demo
    eksperyment.py          program pomiarowy (wersja Python, bonus)
  excel/
    metoda_babilonska.xlsx  arkusz z formułami: iteracje krok po kroku + porównanie z SQRT()

experiment/
  wyniki_cpp.csv           surowe wyniki pomiarów (C++, wymagane zadaniem)
  wyniki_python.csv        surowe wyniki pomiarów (Python, dodatkowe)
```

## Uruchomienie

**C++**
```bash
cd code/cpp
g++ -O2 -std=c++17 babilonska.cpp -o babilonska && ./babilonska
g++ -O2 -std=c++17 eksperyment.cpp -o eksperyment && ./eksperyment > ../../experiment/wyniki_cpp.csv
```

**Python**
```bash
cd code/python
python3 babilonska.py
python3 eksperyment.py > ../../experiment/wyniki_python.csv
```

**Strona**

Statyczny HTML/CSS — wystarczy otworzyć `site/index.html` w przeglądarce, albo uruchomić lokalny
serwer, np.:
```bash
cd site && python3 -m http.server 8000
```

## Wyniki eksperymentu (C++, 1…1 000 000, 5 powtórzeń)

| Próba | sqrt() | Metoda babilońska |
|---|---|---|
| 1 | 0,004118 s | 0,047588 s |
| 2 | 0,003889 s | 0,044553 s |
| 3 | 0,003889 s | 0,044695 s |
| 4 | 0,003935 s | 0,044954 s |
| 5 | 0,004006 s | 0,045020 s |
| **Średnia** | **0,003967 s** | **0,045362 s** |

Metoda babilońska (ε = 10⁻¹⁵) jest ok. **11–12×** wolniejsza niż biblioteczny `sqrt()`, przy
identycznej poprawności wyniku (różnice rzędu 10⁻¹³–10⁻¹⁵). Pełna analiza — w sekcji „Wnioski”
strony internetowej.

## Wykorzystanie AI

Projekt przygotowany z pomocą narzędzi AI (Claude) — wyszukiwanie i weryfikacja informacji
historycznych/matematycznych, pisanie i uruchamianie kodu, przygotowanie HTML/CSS/wykresów oraz
analiza wyników — zgodnie z zasadami zadania. Kod został uruchomiony i zweryfikowany lokalnie
(zgodność wyników obu metod potwierdzona sumami kontrolnymi).
