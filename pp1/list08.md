## Lista zadań 08: Pętle, Instrukcje Skoku i Tablice Jednowymiarowe

Zadania obejmują materiał z wykładu 8, koncentrując się na algorytmach iteracyjnych, sterowaniu przepływem programu (`break`/`continue`) oraz podstawach operacji na tablicach.

### Zadanie 1: Pętla i NWD

Napisz program, który pobiera od użytkownika dwie liczby całkowite `m` oraz `n` (dodatnie lub ujemne) i oblicza największy wspólny dzielnik (NWD) tych liczb.

* Program ma działać w pętli, przerwanej wprowadzeniem liczby `0` (przez którąkolwiek ze zmiennych).

---

### Zadanie 2: Tablice – Dwie największe liczby

Zainicjuj tablicę `arr[N]` typu `int32_t` liczbami pseudolosowymi z zakresu `[-K, +K]`.

* Znajdź i wydrukuj dwie największe liczby z tablicy `arr[N]` (w kolejności malejącej) oraz pozycje/indeksy tych liczb w tablicy.
* `N`, `K` – stałe programowe (zdefiniowane przez `#define`).

---

### Zadanie 3: Tablice Jednowymiarowe – Rotacja cykliczna

Zdefiniuj stałą `#define N 10`. Napisz program, który:

* Wypełnia tablicę `N` liczb całkowitych losowymi wartościami z zakresu 0-99 (wykorzystaj `rand()` oraz `srand()` z `<time.h>`).
* Przesuwa wszystkie elementy tablicy o jedną pozycję w prawo (tzw. rotacja cykliczna).
    * Element z indeksu `0` trafia na `1`, z `1` na `2`... a element z indeksu `N-1` (ostatni) trafia na miejsce `0`.
* Wyświetl zawartość tablicy przed i po przesunięciu, używając pętli `for`.

---

### Zadanie 4: Statystyka Tablicowa

Zadeklaruj tablicę typu `double` i zainicjuj ją 10 dowolnymi liczbami (możesz użyć listy inicjalizacyjnej `{...}`). Napisz program, który obliczy i wyświetli:

* Średnią arytmetyczną elementów.
* Element minimalny i maksymalny.
* Liczbę elementów, które są większe od średniej.

---

### Zadanie 5: Gra Logiczna – Symulator LOTTO

Napisz program symulujący losowanie "Szóstki". Jest to zadanie na wykorzystanie **pętli zagnieżdżonych** i sprawdzania unikalności.

1. **Typowanie:** Poproś użytkownika o podanie 6 unikalnych liczb (1-49) do tablicy `userNumbers`.
    * Użyj pętli `do...while` do walidacji zakresu.
    * Przed zapisaniem liczby sprawdź w pętli, czy nie została już podana wcześniej.
2. **Losowanie:** Program losuje 6 liczb do tablicy `lottoNumbers`.
    * **Ważne:** Tu musisz użyć pętli zagnieżdżonej. Po wylosowaniu liczby (`rand() % 49 + 1`), wewnętrzna pętla musi sprawdzić, czy taka liczba już istnieje w wylosowanym zestawie. Jeśli tak – losujemy ponownie.
3. **Wynik:** Porównaj obie tablice i wypisz, ile liczb trafił użytkownik ("trójka", "czwórka" itd.).