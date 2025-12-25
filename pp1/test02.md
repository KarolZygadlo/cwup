## Kolokwium 2 : Podstawy C

### Zadanie 1: Analizator Ciągu Liczbowego (Pętle i Walidacja)

Napisz program, który pobiera od użytkownika serię liczb całkowitych. Program powinien działać w pętli do momentu podania przez użytkownika wartości `0`, która kończy wprowadzanie danych i nie jest wliczana do statystyk.

**Wymagania szczegółowe:**

1.  **Walidacja danych wejściowych (`do...while`):**
    * Każda wprowadzona liczba musi mieścić się w przedziale `[-50, 50]` (poza zerem kończącym).
    * Użyj pętli `do...while`, aby w przypadku podania liczby spoza zakresu program wyświetlił komunikat błędu i wymusił ponowne podanie poprawnej wartości.
2.  **Logika obliczeniowa (`while` / `if`):**
    * W głównej pętli sterującej zliczaj ilość liczb **nieparzystych ujemnych**.
    * Oblicz **średnią arytmetyczną** wszystkich liczb dodatnich (pamiętaj o rzutowaniu typów przy dzieleniu, np. na `double`).
3.  **Wizualizacja (`for`):**
    * Po zakończeniu wprowadzania danych, wyświetl prosty wykres poziomy. Wypisz znak `*` tyle razy, ile liczb poprawnie wprowadzono do systemu (np. jeśli wprowadzono 5 liczb, program wypisuje `*****`).
4.  **Wyjście:**
    * Wyświetl obliczone statystyki w czytelnej formie.

## Zadanie 2: Projekt "Gra Tekstowa"

Wybierz **jeden** z poniższych wariantów.
* **Wariant A (Podstawowy)** – standarodwe zadanie.
* **Wariant B (Zaawansowany)** – wersja dla ambitnych, chcących się wyrónić.

#### Wariant A: "Labirynt Decyzji"

Stwórz grę tekstową opartą na eksploracji, integrującą kluczowe elementy programowania strukturalnego.

**Wymagania techniczne (co musi zawierać kod):**

1.  **Menu i Sterowanie (`switch`):**
    * Gra toczy się w pętli (np. `while`). W każdej turze wyświetl menu (np. `1. Walcz`, `2. Idź dalej`, `3. Sprawdź stan`).
    * Użyj instrukcji `switch` do obsługi wyboru gracza.
    * Zabezpiecz program przed wyborem nieistniejącej opcji (`default`).
2.  **Losowość Zdarzeń (`rand`, `srand`):**
    * Zainicjuj generator liczb losowych na początku `main`.
    * Wydarzenia (np. siła ataku potwora, znalezienie złota) muszą być generowane losowo.
3.  **Funkcje i Przekazywanie przez Wskaźnik:**
    * Logika zmiany stanu gracza musi być wydzielona do funkcji, np. `void akcja(int *hp, int *gold)`.
    * Funkcja ta musi przyjmować parametry przez **wskaźnik**, aby trwale zmodyfikować życie i złoto zadeklarowane w `main`.
4.  **Tablica stałych napisów:**
    * Zdefiniuj tablicę nazw przeciwników lub lokacji (tablica wskaźników), np.: `const char *names[] = {"Goblin", "Troll", "Smok"};`.
    * Podczas spotkania wyświetlaj losową nazwę z tej tablicy.
5.  **Warunek końcowy:**
    * Gra kończy się, gdy `HP <= 0` lub gracz uzbiera określoną ilość złota.

#### Wariant B: Przygotowanie własnej propozycji gry (dla ambitnych)

Przygotowanie własnej, bardziej rozbudowanej gry, wykorzystującej elementy programowania strukturalnego oraz dodatkowe zagadnienia omówione na zajęciach. Tematyka dowolna (np. RPG, przygodowa, logiczna).