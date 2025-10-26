## Lista 05 - Podstawy programowania w C (Instrukcje warunkowe)

### Zadanie 1: Sprawdzanie pełnoletności

Napisz program, który prosi użytkownika o podanie swojego wieku.

- Program powinien wczytać wiek jako liczbę całkowitą (`int`) za pomocą `scanf()`.
- Używając instrukcji **if-else**, program powinien wyświetlić jeden z dwóch komunikatów:
    - "Jesteś pełnoletni/a." (jeśli wiek jest równy 18 lub większy).
    - "Nie jesteś jeszcze pełnoletni/a." (w przeciwnym razie).

---

### Zadanie 2: Klasyfikacja liczby

Napisz program, który pobiera od użytkownika jedną liczbę całkowitą.

- Program powinien przeanalizować liczbę i wyświetlić jeden z trzech komunikatów, używając struktury **if-else if-else**:
    - "Liczba jest dodatnia."
    - "Liczba jest ujemna."
    - "Liczba to zero."

---

### Zadanie 3: Rok przestępny

Napisz program, który sprawdza, czy podany przez użytkownika rok jest rokiem przestępnym.

Wskazówki:
- Pobierz rok jako liczbę całkowitą.
- Rok jest przestępny, jeśli spełnia jeden z poniższych warunków:
    1. Jest podzielny przez 4, **ale nie jest** podzielny przez 100.
    2. Jest podzielny przez 400.
- Użyj operatorów logicznych (`&&` - AND, `||` - OR) oraz operatora reszty z dzielenia (`%`) wewnątrz instrukcji `if`.
- Przykład logiki warunku: `if ((rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0))`

---

### Zadanie 4: Prosty kalkulator

Napisz program, który działa jak prosty kalkulator.

1.  Pobierz od użytkownika dwie liczby zmiennoprzecinkowe (typu `double`).
2.  Pobierz od użytkownika jeden znak (`char`) reprezentujący operację (`+`, `-`, `*`, `/`).
3.  Użyj serii instrukcji **if-else if**, aby sprawdzić, który operator wybrał użytkownik i wykonaj odpowiednie działanie.
4.  **Obsługa błędu:** W przypadku dzielenia (`/`), użyj **zagnieżdżonej instrukcji if**, aby sprawdzić, czy druga liczba nie jest zerem. Jeśli jest, wyświetl komunikat "Błąd: Dzielenie przez zero!".
5.  Jeśli użytkownik wprowadzi nieobsługiwany operator, wyświetl komunikat "Nieznany operator."

---

### Zadanie 5: Prosta gra tekstowa "Rozdroża"

Napisz prostą grę tekstową, w której użytkownik podejmuje decyzje prowadzące do różnych zakończeń. Użyj **zagnieżdżonych instrukcji if-else**.

Struktura gry:
1.  **Start:** Wyświetl powitanie: "Stoisz na rozdrożu w ciemnym lesie. Możesz iść w (1) lewo lub (2) prawo. Którą ścieżkę wybierasz? (wpisz 1 lub 2)".
2.  Pobierz wybór użytkownika (`int wybor1`).
3.  **Scenariusz główny (if-else):**
    - **Jeśli** `wybor1 == 1` (w lewo):
        - Wyświetl: "Idąc w lewo, docierasz do starej chaty. (1) Wchodzisz do środka, (2) Omijasz ją."
        - Pobierz `wybor2`.
        - **Jeśli** `wybor2 == 1`: Wyświetl "W środku znajdujesz skrzynię ze skarbem! Wygrałeś!"
        - **W przeciwnym razie (else)**: Wyświetl "Omijając chatę, gubisz się w lesie. Koniec gry."
    - **Jeśli** `wybor1 == 2` (w prawo):
        - Wyświetl: "Idąc w prawo, spotykasz niedźwiedzia. (1) Uciekasz, (2) Próbujesz walczyć."
        - Pobierz `wybor3`.
        - **Jeśli** `wybor3 == 1`: Wyświetl "Udało Ci się uciec. Jesteś bezpieczny. Koniec gry."
        - **W przeciwnym razie (else)**: Wyświetl "Niedźwiedź był zbyt silny. Przegrałeś."
    - **W przeciwnym razie (else)** (gdy `wybor1` nie jest ani 1, ani 2):
        - Wyświetl: "Stoisz w miejscu tak długo, że zapada noc. Zgubiłeś się."

---

### Zadanie 6 (dla chętnych): Klasyfikacja trójkąta

Napisz program, który prosi użytkownika o podanie długości trzech boków trójkąta (`a`, `b`, `c`).

Wymagania:
1.  Pobierz trzy długości jako `double`.
2.  **Warunek wstępny (Warunek trójkąta):** Najpierw sprawdź, czy z podanych boków **w ogóle da się zbudować trójkąt**. Suma dowolnych dwóch boków musi być większa od trzeciego boku.
    - Warunek: `$a + b > c$ ORAZ $a + c > b$ ORAZ $b + c > a$.
3.  **Jeśli** warunek trójkąta **nie jest** spełniony, wyświetl: "Z tych boków nie można zbudować trójkąta."
4.  **Jeśli** warunek trójkąta **jest** spełniony (użyj bloku `else`), przejdź do klasyfikacji (użyj zagnieżdżonych `if-else if-else`):
    - **Jeśli** `a == b` i `b == c`: Wyświetl "Trójkąt równoboczny."
    - **Jeśli** `a == b` lub `a == c` lub `b == c`: Wyświetl "Trójkąt równoramienny."
    - **W przeciwnym razie**: Wyświetl "Trójkąt różnoboczny."