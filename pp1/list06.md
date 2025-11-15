## Lista Zadań 6: Instrukcje Warunkowe, Operatory, Tablice Wskaźników i Rzutowanie Typów

Ta lista zadań obejmuje materiał z instrukcji warunkowych (`if`, `switch`), operatorów (logicznych, relacyjnych, trójargumentowych, złożonych), tablic wskaźników oraz rzutowania typów.

### Część 1: Instrukcje `if`, `if-else` i Operator Trójargumentowy

Zadania w tej części koncentrują się na podejmowaniu decyzji za pomocą `if`, sprawdzaniu wielu warunków oraz obsłudze danych wejściowych.

#### Zadanie 1.1: Warunek Trójkąta

Napisz program, który prosi użytkownika o podanie trzech długości boków trójkąta (jako liczby `double`).

* Użyj **jednej** funkcji `scanf()` do wczytania wszystkich trzech wartości.
* Najpierw sprawdź, czy z podanych boków **da się zbudować trójkąt**.
    * *Warunek (Warunek trójkąta):* Suma długości dowolnych dwóch boków musi być większa od długości trzeciego boku (`a+b > c` ORAZ `a+c > b` ORAZ `b+c > a`).
* Używając instrukcji `if-else`, wyświetl jeden z komunikatów:
    * "Z podanych boków można zbudować trójkąt."
    * "Z podanych boków nie można zbudować trójkąta."

#### Zadanie 1.2: Pole Trójkąta - Wzór Herona

Rozbuduj program z **Zadania 1.1**.

* Jeśli warunek trójkąta **jest** spełniony, program powinien dodatkowo obliczyć i wyświetlić pole tego trójkąta, korzystając ze wzoru Herona:
    1.  Oblicz połowę obwodu: $s = (a + b + c) / 2$
    2.  Oblicz pole: $Pole = \sqrt{s(s-a)(s-b)(s-c)}$
* Jeśli warunek **nie jest** spełniony, program powinien wyświetlić tylko komunikat z Zadania 1.1.
* *Wskazówka:* Aby użyć funkcji `sqrt()`, musisz dodać `#include <math.h>`.

#### Zadanie 1.3: Układ Równań Liniowych

Napisz program, który rozwiązuje układ dwóch równań liniowych metodą wyznaczników:
$ax + by = c$
$dx + ey = f$

1.  Pobierz od użytkownika 6 współczynników (`a`, `b`, `c`, `d`, `e`, `f`) jako liczby `float`. Wczytaj współczynniki `a, b, c` jedną funkcją `scanf()`, a `d, e, f` drugą.
2.  Oblicz wyznaczniki:
    * Wyznacznik główny: $W = a \cdot e - b \cdot d$
    * Wyznacznik $x$: $W_x = c \cdot e - b \cdot f$
    * Wyznacznik $y$: $W_y = a \cdot f - c \cdot d$
3.  Używając zagnieżdżonych instrukcji `if-else-if`, przeanalizuj wartości wyznaczników, aby określić typ rozwiązania:
    * **Jeśli $W \neq 0$:** Układ jest oznaczony. Oblicz $x = W_x / W$ i $y = W_y / W$ i wyświetl je.
    * **Jeśli $W == 0$ ORAZ $W_x == 0$ ORAZ $W_y == 0$:** Układ jest nieoznaczony (ma nieskończenie wiele rozwiązań).
    * **Jeśli $W == 0$** (a pozostałe warunki nie są spełnione): Układ jest sprzeczny (brak rozwiązań).
4.  Wyświetl wyniki `x` i `y` z dokładnością do 3 miejsc po przecinku (np. używając `%.3f`).

#### Zadanie 1.5: Wartość Bezwzględna (Operator Trójargumentowy)

Napisz program, który prosi użytkownika o podanie jednej liczby całkowitej. Wykorzystaj **operator trójargumentowy (`?:`)**, aby obliczyć i wyświetlić wartość bezwzględną tej liczby.

* *Przykład:* `wynik = (liczba < 0) ? -liczba : liczba;`
* Wyświetl komunikat: "Wartość bezwzględna z [liczba] to [wynik]."

---

### Część 2: Instrukcja `switch`

Zadania w tej części skupiają się na instrukcji `switch` jako alternatywie dla `if-else-if`, w tym na grupowaniu `case` i niestandardowych rozszerzeniach.

#### Zadanie 2.1: Dzień Tygodnia

```c
#include <stdio.h> // printf(), getchar()
#include <stdlib.h> // rand(), srand(), system()
#include <time.h> // time() - arg. srand()
// deklaracja typu wyliczeniowego enum dzien
enum dzien { PN, WT, SR, CZW, PT, SOB, NIEDZ };

int main(int argc, char* argv[])
{
    system("chcp 65001 >nul");
    enum dzien wolny; // wolny - zmienna typu enum dzien
    srand(time(NULL)); // inicjowanie generatora liczb pseudolosowych
    wolny = rand() % 7; // losowanie numeru dnia z zakresu [0, 6]
    printf("\nDzień bez nudnych wykładów: %u\n", wolny);
    fflush(stdin);
    getchar();
    return 0;
}
```

Zmodyfikuj program, który losuje liczbę od 0 do 6.

* Bazując na istniejącym kodzie, dodaj instrukcję **`switch`**, która przyjmie wylosowaną liczbę.
* Dla każdej wartości (0-6) wyświetl odpowiednią nazwę dnia tygodnia.
    * `case 0:` -> "poniedziałek"
    * `case 1:` -> "wtorek"
    * ...itd.
* Pamiętaj o użyciu `break;` po każdym `case`.

#### Zadanie 2.2: Mini-Kalkulator (z `switch`)

Napisz program, który działa jak prosty kalkulator.
1.  Pobierz od użytkownika dwie liczby (`double`).
2.  Pobierz od użytkownika jeden znak (`char`) reprezentujący operację: `+`, `-`, `*`, `/`.
3.  Użyj instrukcji **`switch`** na wczytanym znaku (operatorze).
4.  W każdym `case` wykonaj odpowiednie obliczenie i wyświetl wynik.
5.  W `case '/'` (dzielenie), użyj **zagnieżdżonej instrukcji `if`**, aby sprawdzić, czy druga liczba nie jest zerem. Jeśli jest, wyświetl błąd.
6.  Dodaj blok `default:`, który wyświetli komunikat "Nieznany operator."

#### Zadanie 2.3: Grupowanie `case` (Dzień Roboczy)

Napisz program, który prosi użytkownika o podanie numeru dnia tygodnia (1 dla poniedziałku, 7 dla niedzieli).

* Użyj instrukcji `switch` i **grupowania `case`** (tzn. wielu `case` prowadzących do tego samego kodu), aby wyświetlić jeden z trzech komunikatów:
    * "Dzień roboczy." (dla przypadków 1, 2, 3, 4, 5)
    * "Dzień wolny (weekend)." (dla przypadków 6, 7)
    * "Błędny numer dnia." (dla `default:`)

#### Zadanie 2.4: Skala Beauforta

Napisz program, który prosi o siłę wiatru w km/h i wyświetla opis oraz stan morza (zgodnie ze skalą Beauforta).

* Zaimplementuj to przy użyciu instrukcji `switch` z **niestandardowym rozszerzeniem GCC dla zakresów** (`case min ... max:`).
* Pobierz prędkość wiatru (`int predkosc`).
* Zabezpiecz program przed wartościami ujemnymi, używając `if` na początku.
* Użyj `switch` do klasyfikacji:
    * `case 0 ... 1:` -> "Cisza", "Morze gładkie"
    * `case 2 ... 5:` -> "Powiew", "Drobne zmarszczki"
    * `case 6 ... 11:` -> "Słaby wiatr", "Małe falki"
    * `case 12 ... 19:` -> "Łagodny wiatr", "Duże falki..."
    * *(Kontynuuj wg skali z Wikipedii)*
    * `default:` -> (dla wartości powyżej górnego limitu skali) "Huragan", "Wyjątkowo wzburzone"

#### Zadanie 2.5: Miesiące (Tablica Wskaźników)

Napisz program, który prosi użytkownika o numer miesiąca (1-12).

* Zamiast używać `switch` lub `if-else-if`, zdefiniuj **tablicę wskaźników na stałe łańcuchy znaków** (`const char*`).
    * `const char* miesiace[] = { "Styczeń", "Luty", ... , "Grudzień" };`
* Pobierz numer miesiąca `int n`.
* Użyj `if`, aby sprawdzić, czy `n` jest w zakresie `1 ... 12`.
* Jeśli tak, wyświetl nazwę miesiąca, pobierając ją z tablicy: `printf("%s", miesiace[n - 1]);`.
* Jeśli nie, wyświetl błąd.

---

### Część 3: Zadania dla chętnych

#### Zadanie 3.1: Pole Trójkąta ze Współrzędnych

Napisz program, który oblicza pole trójkąta, ale tym razem na podstawie **współrzędnych jego wierzchołków**.

1.  Pobierz od użytkownika współrzędne trzech punktów: (x1, y1), (x2, y2), (x3, y3). Użyj `double` dla wszystkich.
2.  Oblicz długości trzech boków (a, b, c), korzystając ze wzoru na odległość między dwoma punktami:
    $d = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}$
    *(Będziesz potrzebować `#include <math.h>` dla `sqrt()` i `pow()`).*
3.  Mając boki `a`, `b`, `c`, wykorzystaj poprzednią logikę:
    * Sprawdź, czy spełniony jest warunek trójkąta.
    * Jeśli tak, oblicz pole wzorem Herona i je wyświetl.
    * Jeśli nie, wyświetl komunikat o błędzie.

---

#### Zadanie 3.2: Gra Tekstowa "Labirynt" (Zagnieżdżone `if` i `switch`)

Stwórz prostą grę tekstową, używając **zagnieżdżonych struktur `if` oraz `switch`**.

1.  **Start:** "Stoisz w ciemnym korytarzu. Widzisz troje drzwi: (1) Czerwone, (2) Zielone, (3) Niebieskie. Które wybierasz? (1, 2, 3)". Pobierz `int wyborDrzwi`.
2.  Użyj **`switch(wyborDrzwi)`** do obsługi wyboru:
    * **`case 1` (Czerwone):**
        * "Pokój jest gorący. Na środku stoi skrzynia. Czy otwierasz? (t/n)". Pobierz `char decyzja`.
        * Użyj **`if (decyzja == 't')`** -> "W środku jest złoto! Wygrałeś!".
        * `else` -> "Uniknąłeś pułapki. Wracasz na korytarz. Koniec gry."
    * **`case 2` (Zielone):**
        * "Trafiasz do ogrodu. Spotykasz mędrca. 'Odpowiedz na zagadkę: Co ma klucze, ale nie otwiera zamków?' (1) Fortepian, (2) Mapa". Pobierz `int zagadka`.
        * Użyj **`if (zagadka == 1)`** -> "Dobra odpowiedź! Mędrzec daje Ci klucz. Wygrałeś!".
        * `else` -> "Zła odpowiedź. Mędrzec Cię wygania. Koniec gry."
    * **`case 3` (Niebieskie):**
        * "Drzwi zatrzaskują się za Tobą. Pokój jest pusty, poza małą dźwignią na ścianie. Czy ją pociągasz? (t/n)". Pobierz `char dzwignia`.
        * Użyj **`if (dzwignia == 't')`** -> "Otwiera się zapadnia! Spadasz w ciemność. Przegrałeś.".
        * `else` -> "Stoisz w miejscu, aż gaśnie światło. Przegrałeś."
    * **`default:`**
        * "Potykasz się w ciemności i wracasz na początek. Koniec gry."