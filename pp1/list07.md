## Lista zadań 07: Instrukcje Iteracyjne

### Zadanie 1: Pętla `while` – Suma kwadratów

Napisz program, który prosi użytkownika o podanie liczby całkowitej `N`.

* Za pomocą pętli **`while`**, program ma obliczyć sumę kwadratów liczb od 1 do `N` (czyli $1^2 + 2^2 + ... + N^2$).
* Program powinien najpierw sprawdzić, czy `N` jest dodatnie. Jeśli `N` jest 0 lub ujemne, pętla nie powinna się w ogóle wykonać, a suma powinna wynosić 0.
* Wyświetl wynik, np. "Suma kwadratów od 1 do 5 wynosi: 55".

---

### Zadanie 2: Pętla `do...while` – Walidacja danych wejściowych

Napisz program, który prosi użytkownika o podanie liczby całkowitej z określonego przedziału, np. od 1 do 100.

* Użyj pętli **`do...while`**, aby program pytał użytkownika o podanie liczby tak długo, aż wprowadzona wartość będzie poprawna (będzie w zakresie 1-100).
* Pętla `do...while` gwarantuje, że użytkownik zostanie poproszony o liczbę **co najmniej raz**.
* Jeśli użytkownik poda liczbę spoza zakresu, program powinien wyświetlić komunikat "Błędna wartość. Spróbuj ponownie." i powtórzyć pętlę.
* Gdy użytkownik poda poprawną liczbę, program powinien wyświetlić "Wprowadzono poprawną liczbę: [liczba]." i zakończyć działanie.

---

### Zadanie 3: Pętla `for` – Tabliczka mnożenia

Napisz program, który prosi użytkownika o podanie jednej liczby całkowitej `N`.

* Używając pętli **`for`**, program ma wyświetlić tabliczkę mnożenia dla tej liczby, od 1 do 10.
* Format wyjścia powinien być następujący (dla `N = 7`):
    ```
    7 x 1 = 7
    7 x 2 = 14
    ...
    7 x 10 = 70
    ```

---

### Zadanie 4: Trzy wersje pętli – Potęgowanie

Napisz program, który pobiera od użytkownika dwie liczby całkowite `m` i `n` (typu `int32_t`) i wyświetla wartości kolejnych potęg liczby `BASE` (zdefiniowanej jako stała) od $BASE^m$ do $BASE^n$.

* **Implementacja:** Program należy napisać w **trzech oddzielnych wersjach**, używając kolejno pętli:
    a) `while`
    b) `do...while`
    c) `for`
* **Stałe symboliczne:** Użyj dyrektyw `#define`, aby ułatwić modyfikację programu:
    ```c
    #define BASE 2 
    #define LOW_LIMIT -5 
    #define HIGH_LIMIT 20
    ```
* **Walidacja danych:** Zabezpiecz program przed wprowadzeniem niepoprawnych danych. Użyj pętli `do...while`, aby wymusić podanie poprawnych `m` i `n` zgodnie z warunkami:
    * `m` nie może być mniejsze niż `LOW_LIMIT`.
    * `n` nie może być większe niż `HIGH_LIMIT`.
    * `n` nie może być mniejsze niż `m`.
* **Wyjście:** Wyniki potęgowania wyświetlaj z dokładnością do 4 miejsc po przecinku (np. `%.4f`).
* *Wskazówka:* Do obliczenia potęgi użyj funkcji `pow(baza, wykładnik)` z biblioteki `math.h`. Pamiętaj, że `pow()` operuje na typie `double`.

---

### Zadanie 5: Pętle zagnieżdżone – Rysowanie trójkąta

Napisz program, który prosi użytkownika o podanie wysokości trójkąta `h` (liczba całkowita).

* Użyj **zagnieżdżonych pętli `for`** (jedna pętla wewnątrz drugiej), aby wyświetlić na ekranie trójkąt prostokątny o wysokości `h` zbudowany z gwiazdek (`*`).
* **Przykład dla `h = 4`:**
    ```
    *
    **
    ***
    ****
    ```
* *Wskazówka:* Pętla zewnętrzna powinna iterować od 1 do `h` (kontrolując wiersze), a pętla wewnętrzna powinna iterować od 1 do numeru bieżącego wiersza (kontrolując liczbę gwiazdek w wierszu).
