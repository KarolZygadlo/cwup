## Lista zadań 09: Funkcje, Wskaźniki i Rekurencja

Zadania obejmują materiał z wykładów 9 i 10, w tym definiowanie funkcji, przekazywanie parametrów przez adres, rekurencję oraz obsługę tablic wielowymiarowych.

### Zadanie 1: Funkcje i Wskaźniki – Równanie Kwadratowe

Napisz funkcję `solveQuadratic`, która oblicza pierwiastki równania $ax^2 + bx + c = 0$. Funkcja ma zwracać liczbę rozwiązań, a same pierwiastki "oddawać" przez wskaźniki.

* **Prototyp:** `int solveQuadratic(double a, double b, double c, double *x1, double *x2);`
* **Funkcja zwraca:**
    * `2` – dwa rozwiązania (wpisz je pod adresy `x1` i `x2`).
    * `1` – jedno rozwiązanie (wpisz pod `x1`).
    * `0` – brak rozwiązań rzeczywistych.
* W `main` pobierz współczynniki, wywołaj funkcję i obsłuż wynik odpowiednim komunikatem.

---

### Zadanie 2: Rekurencja – Potęgowanie Szybkie

Napisz funkcję rekurencyjną `power(base, exponent)` obliczającą $base^{exponent}$ dla liczb całkowitych.

* **Przypadek bazowy:** Jeśli `exponent == 0`, zwróć `1`.
* **Krok rekurencyjny:** `base * power(base, exponent - 1)`.
* Porównaj to rozwiązanie z podejściem iteracyjnym z poprzedniej listy zadań.

---

### Zadanie 3: Funkcje i Tablice – Czy posortowana?

Napisz funkcję, która przyjmuje tablicę liczb całkowitych oraz jej rozmiar i sprawdza, czy liczby są ułożone rosnąco.

* **Prototyp:** `int isSorted(const int *arr, int n);` (słowo `const` oznacza, że funkcja nie modyfikuje tablicy).
* Funkcja powinna zwrócić `1` (prawda), jeśli tablica jest posortowana, lub `0` (fałsz) w przeciwnym razie.
* W `main` przetestuj funkcję na dwóch tablicach: `{1, 2, 5, 8, 10}` oraz `{1, 5, 2, 8, 10}`.

---

### Zadanie 4: Tablice 2D – Transpozycja Macierzy

Napisz program operujący na macierzy o wymiarach `M x N` (zdefiniuj stałe, np. 3 i 4).

* Napisz funkcję `printMatrix`, która wyświetla macierz w ładnym formacie.
* Napisz funkcję `transposeMatrix`, która wykonuje transpozycję (zamianę wierszy z kolumnami).
* **Uwaga:** Ponieważ macierz nie musi być kwadratowa, wynik transpozycji zapisz w drugiej tablicy o wymiarach `N x M`.
* Zainicjuj macierz kolejnymi liczbami całkowitymi, wyświetl ją, dokonaj transpozycji i wyświetl wynik.

---

### Zadanie 5: Gra Konsolowa – "Kółko i Krzyżyk"

Stwórz prostą grę dla dwóch graczy, wykorzystując podział na funkcje i tablicę 2D. To zadanie rozwija ideę "programu z menu" omawianą na wykładzie.

* **Dane:** Tablica `char board[3][3]`, początkowo wypełniona spacjami `' '`.
* **Wymagane funkcje:**
    * `void rysujPlansze(char b[3][3])` – czyści ekran i rysuje siatkę z aktualnym stanem.
    * `int wykonajRuch(char b[3][3], int wiersz, int kolumna, char gracz)` – wstawia znak (`'X'` lub `'O'`), jeśli pole jest puste. Zwraca `1` (sukces) lub `0` (błąd/zajęte).
    * `char sprawdzWygrana(char b[3][3])` – sprawdza wiersze, kolumny i przekątne. Zwraca `'X'`, `'O'` (zwycięzca) lub `' '` (brak wygranej).
* **Logika (`main`):** Pętla trwa do momentu wygranej lub zapełnienia planszy (remis). Gracze wykonują ruchy na zmianę.
