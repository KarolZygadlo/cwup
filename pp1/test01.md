## Kolokwium 1: Podstawy C

### Zadanie 1: System ocen

Napisz program, który prosi użytkownika o podanie liczby punktów uzyskanych z testu (w skali 0-100).

* Program powinien wczytać punkty jako liczbę całkowitą (`int`).
* Używając struktury **if-else if-else**, program powinien wyświetlić odpowiednią ocenę:
    * "Ocena: 5.0" (jeśli punkty > 90)
    * "Ocena: 4.5" (jeśli punkty > 80)
    * "Ocena: 4.0" (jeśli punkty > 70)
    * "Ocena: 3.5" (jeśli punkty > 60)
    * "Ocena: 3.0" (jeśli punkty >= 50)
    * "Ocena: 2.0" (w przeciwnym razie)

---

### Zadanie 2: Parzysta czy nieparzysta

Napisz program, który pobiera od użytkownika jedną liczbę całkowitą.

* Program powinien sprawdzić, czy podana liczba jest parzysta, czy nieparzysta.
* Używając instrukcji **if-else** oraz operatora reszty z dzielenia (`%`), wyświetl jeden z dwóch komunikatów:
    * "Liczba jest parzysta."
    * "Liczba jest nieparzysta."

---

### Zadanie 3: Kwalifikacja do wyjścia na basen

Napisz program, który decyduje, czy pogoda jest odpowiednia na wyjście na basen.

* Pobierz od użytkownika temperaturę powietrza (jako `int`).
* Pobierz od użytkownika informację, czy pada deszcz (jako `int`, gdzie **1** oznacza "pada", a **0** oznacza "nie pada").
* Program powinien wyświetlić "Można iść na basen.", jeśli spełniony jest jeden z warunków:
    1.  Temperatura jest wyższa niż 25 stopni **I JEDNOCZEŚNIE** nie pada deszcz.
    2.  LUB temperatura jest wyższa niż 35 stopni (niezależnie od deszczu).
* W przeciwnym razie program powinien wyświetlić "Lepiej zostać w domu.".
* *Wskazówka: Użyj operatorów `&&` oraz `||`.*

---

### Zadanie 4: Mini-kalkulator naukowy

Napisz program, który wykonuje jedną z trzech operacji na jednej liczbie.

1.  Pobierz od użytkownika liczbę zmiennoprzecinkową (`double`) o nazwie `liczba`.
2.  Pobierz od użytkownika znak (`char`) reprezentujący operację:
    * `'s'` – pierwiastek kwadratowy ($sqrt$)
    * `'q'` – podniesienie do kwadratu ($x^2$)
    * `'i'` – odwrotność ($1/x$)
3.  Użyj instrukcji **if-else if**, aby wybrać operację.
4.  **Obsługa błędów (zagnieżdżone if):**
    * Przy próbie pierwiastkowania (`'s'`), jeśli `liczba` jest ujemna, wyświetl "Błąd: Nie można obliczyć pierwiastka z liczby ujemnej."
    * Przy próbie obliczenia odwrotności (`'i'`), jeśli `liczba` jest równa 0, wyświetl "Błąd: Dzielenie przez zero."
5.  Jeśli operacja jest możliwa, wyświetl wynik (np. "Wynik: 1.414").
6.  Jeśli wprowadzono nieznany operator, wyświetl "Nieznana operacja."

*Wskazówka: Aby użyć funkcji pierwiastka `sqrt()`, musisz dodać na początku kodu `#include <math.h>`.*

---

### Zadanie 5: Gra tekstowa "Tajemniczy Zamek"

Napisz prostą grę tekstową, w której użytkownik podejmuje decyzje prowadzące do różnych zakończeń. Użyj **zagnieżdżonych instrukcji if-else**.

Struktura gry:
1.  **Start:** Wyświetl: "Budzisz się w ciemnym lochu. Przed Tobą (1) ciężkie dębowe drzwi i (2) wąski tunel. Co wybierasz? (wpisz 1 lub 2)".
2.  Pobierz wybór użytkownika (`int wybor1`).
3.  **Scenariusz główny (if-else):**
    * **Jeśli** `wybor1 == 1` (drzwi):
        * Wyświetl: "Drzwi prowadzą do sali tronowej. Na tronie siedzi król. (1) Skłaniasz się nisko, (2) Ignorujesz go i idziesz dalej."
        * Pobierz `wybor2`.
        * **Jeśli** `wybor2 == 1`: Wyświetl "Król jest pod wrażeniem Twoich manier. Mianuje Cię swoim doradcą. Wygrałeś!"
        * **W przeciwnym razie (else)**: Wyświetl "Za obrazę majestatu strażnicy wtrącają Cię z powrotem do lochu. Koniec gry."
    * **Jeśli** `wybor1 == 2` (tunel):
        * Wyświetl: "Czołgasz się przez tunel i docierasz do skarbca pilnowanego przez śpiącego smoka. (1) Próbujesz się przekraść po złoto, (2) Wycofujesz się po cichu."
        * Pobierz `wybor3`.
        * **Jeśli** `wybor3 == 1`: Wyświetl "Smok obudził się i zionął ogniem. Przegrałeś."
        * **W przeciwnym razie (else)**: Wyświetl "Udało Ci się bezpiecznie wrócić do lochu. Zawsze to jakieś wyjście... Koniec gry."
    * **W przeciwnym razie (else)** (gdy `wybor1` nie jest ani 1, ani 2):
        * Wyświetl: "Z niezdecydowania potykasz się i wpadasz w ukrytą zapadnię. Koniec gry."