## Lista 04 - Podstawy programowania w C

### Zadanie 1: Struktura programu w C

Napisz, skompiluj i uruchom minimalny program w C, który wyświetli tekst "Witaj Swiecie!". W kodzie użyj komentarzy do opisania kluczowych elementów:

- Dyrektywy preprocesora (`#include`).

- Funkcji `main` jako punktu startowego programu.

- Instrukcji `printf`.

- Instrukcji `return`.

### Zadanie 2: Eksploracja typów danych

Wykorzystaj kod z Przykładu 1 z wykładu nr 3 (dotyczący typów całkowitych).

1. *Przepełnienie zakresu (Overflow)*: Zadeklaruj zmienną typu `unsigned char` i przypisz jej maksymalną wartość (255). Następnie zwiększ ją o 1 i wyświetl wynik. Dla liczb bez znaku, przepełnienie powoduje otrzymanie wartości modulo 2^n.

2. *Typ logiczny*: Dołącz bibliotekę `stdbool.h`. Zadeklaruj zmienną typu `bool` i przypisz jej wartość `true` lub `false`. Wyświetl jej wartość za pomocą specyfikatora `%u`.

### Zadanie 3: Twierdzenie Pitagorasa

Napisz program, który prosi użytkownika o podanie długości przyprostokątnych trójkąta prostokątnego (`a` i `b`), a następnie oblicza długość przeciwprostokątnej (`c`).

Wskazówki: 

- Dołącz bibliotekę `math.h`. 

- Użyj funkcji `scanf()` do pobrania wartości od użytkownika. 

- Skorzystaj z twierdzenia Pitagorasa: $c = \sqrt{a^2 + b^2}$. 

- Do obliczenia potęgi użyj funkcji `pow(x, y)`. 

- Do obliczenia pierwiastka kwadratowego użyj funkcji `sqrt(x)`.

### Zadanie 4: Konwersja temperatury

Napisz program, który konwertuje temperaturę z stopni Celsjusza na stopnie Fahrenheita i Kelwina.

Wymagania:

- Pobierz od użytkownika temperaturę w Celsjuszach.

- Użyj typu `double` dla precyzji.

- Wzory:

    - Fahrenheit: $F = (C \cdot \frac{9}{5}) + 32$

    - Kelwin: $K = C + 273.15$

- Wyświetl wyniki z odpowiednimi etykietami.

### Zadanie 5: Operacje na znakach

Napisz program, który prosi użytkownika o wprowadzenie jednej małej litery, a następnie wyświetla ją jako dużą literę oraz jej kod ASCII.

Wymagania:

- Użyj typu `char` do przechowywania znaku.

- Do konwersji na dużą literę wykorzystaj fakt, że w tablicy ASCII małe i duże litery są od siebie oddalone o stałą wartość (32). Możesz odjąć 32 od kodu ASCII małej litery, aby uzyskać kod dużej.

- Do wyświetlenia kodu ASCII znaku użyj specyfikatora formatu `%d`.

### Zadanie 6 (dla chętnych): Równanie kwadratowe

Napisz program, który oblicza pierwiastki równania kwadratowego w postaci $ax^2 + bx + c = 0$.

Wymagania:

- Program powinien wczytać od użytkownika wartości współczynników a, b i c za pomocą scanf().

- Oblicz deltę: $\Delta = b^2 - 4ac$.

- Użyj instrukcji warunkowych (if-else if-else), aby obsłużyć trzy przypadki:

    - $\Delta > 0$: Dwa pierwiastki rzeczywiste: $x_1 = \frac{-b - \sqrt{\Delta}}{2a}$, $x_2 = \frac{-b + \sqrt{\Delta}}{2a}$.
    
    - $\Delta = 0$: Jeden pierwiastek rzeczywisty: $x_0 = \frac{-b}{2a}$.

    - $\Delta < 0$: Brak pierwiastków rzeczywistych (wystarczy wyświetlić komunikat).
    
- Wyświetl odpowiednie wyniki dla każdego przypadku.
