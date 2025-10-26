#include <stdio.h>
#include <stdint.h>
#include <math.h>

// --- ZADANIE 1: Operacje arytmetyczne ---
// Program wykonuje podstawowe operacje arytmetyczne na typach o większej precyzji:
// - int64_t: 64-bitowa liczba całkowita o gwarantowanym rozmiarze.
// - long double: typ zmiennoprzecinkowy o najwyższej dostępnej precyzji.
void task01(void) {
    // --- Operacje na liczbach typu int64_t ---
    // Deklaracja zmiennych dla argumentów i wyników operacji całkowitoliczbowych.
    int64_t arg1_i, arg2_i, add_i, sub_i, mul_i, div_i, mod_i;

    // Wyświetlenie nagłówka sekcji.
    puts("\n--- Operacje arytmetyczne na liczbach typu int64_t ---");
    printf("Podaj dwie liczby calkowite oddzielone spacja: ");

    // Wczytanie dwóch 64-bitowych liczb całkowitych.
    // Używamy specyfikatora formatu "%lld" dla typu int64_t (long long).
    scanf("%lld %lld", &arg1_i, &arg2_i);

    // Wykonanie podstawowych operacji arytmetycznych.
    add_i = arg1_i + arg2_i;  // Dodawanie.
    sub_i = arg1_i - arg2_i;  // Odejmowanie.
    mul_i = arg1_i * arg2_i;  // Mnożenie.

    // Wyświetlenie wyników operacji całkowitoliczbowych.
    printf("%lld + %lld = %lld\n", arg1_i, arg2_i, add_i);
    printf("%lld - %lld = %lld\n", arg1_i, arg2_i, sub_i);
    printf("%lld * %lld = %lld\n", arg1_i, arg2_i, mul_i);

    // Zabezpieczenie przed dzieleniem przez zero.
    if (arg2_i != 0) {
        div_i = arg1_i / arg2_i;  // Dzielenie całkowite.
        mod_i = arg1_i % arg2_i;  // Operator modulo (reszta z dzielenia).
        printf("%lld / %lld = %lld\n", arg1_i, arg2_i, div_i);
        printf("Reszta z dzielenia %lld %% %lld = %lld\n", arg1_i, arg2_i, mod_i);
    } else {
        // Informacja o niemożności dzielenia przez zero.
        puts("Dzielenie przez zero jest niedozwolone.");
    }

    // --- Operacje na liczbach typu long double ---
    // Deklaracja zmiennych dla argumentów i wyników operacji zmiennoprzecinkowych.
    long double arg1_ld, arg2_ld, add_ld, sub_ld, mul_ld, div_ld;

    // Wyświetlenie nagłówka sekcji.
    puts("\n--- Operacje arytmetyczne na liczbach typu 'long double' ---");
    printf("Podaj dwie liczby rzeczywiste oddzielone spacja: ");

    // Wczytanie dwóch liczb typu long double.
    // Używamy specyfikatora formatu "%Lf".
    scanf("%Lf %Lf", &arg1_ld, &arg2_ld);

    // Wykonanie podstawowych operacji arytmetycznych.
    add_ld = arg1_ld + arg2_ld;  // Dodawanie.
    sub_ld = arg1_ld - arg2_ld;  // Odejmowanie.
    mul_ld = arg1_ld * arg2_ld;  // Mnożenie.

    // Wyświetlenie wyników z formatowaniem do 4 miejsc po przecinku (%.4Lf).
    printf("%.4Lf + %.4Lf = %.4Lf\n", arg1_ld, arg2_ld, add_ld);
    printf("%.4Lf - %.4Lf = %.4Lf\n", arg1_ld, arg2_ld, sub_ld);
    printf("%.4Lf * %.4Lf = %.4Lf\n", arg1_ld, arg2_ld, mul_ld);

    // Zabezpieczenie przed dzieleniem przez zero dla liczb zmiennoprzecinkowych.
    if (arg2_ld != 0.0) {
        div_ld = arg1_ld / arg2_ld;  // Dzielenie zmiennoprzecinkowe.
        printf("%.4Lf / %.4Lf = %.4Lf\n", arg1_ld, arg2_ld, div_ld);
    } else {
        // Informacja o niemożności dzielenia przez zero.
        puts("Dzielenie przez zero jest niedozwolone.");
    }
}

// --- ZADANIE 2: Konwersja centymetrów ---
// Program przelicza podaną przez użytkownika długość w centymetrach
// na cale i stopy.
void task02(void) {
    // Definicja stałych przeliczeniowych dla czytelności kodu.
    const double CM_PER_INCH = 2.54;      // Jeden cal to 2.54 centymetra.
    const int INCHES_PER_FOOT = 12;       // Jedna stopa to 12 cali.

    // Deklaracja zmiennych. Używamy 'double' dla precyzji.
    double centimeters, inches, feet;
    // Prośba o podanie danych.
    printf("\nPodaj dlugosc w centymetrach: ");

    // Wczytanie wartości od użytkownika do zmiennej 'centimeters'.
    // Specyfikator "%lf" jest używany dla typu double w scanf.
    scanf("%lf", &centimeters);

    // Obliczenia:
    // 1. Przelicz centymetry na cale.
    inches = centimeters / 2.54;
    // 2. Przelicz cale na stopy.
    feet = inches / 12;

    // Wyświetlenie wyników.
    // Używamy specyfikatora "%.2f", aby ograniczyć wynik do 2 miejsc po przecinku.
    printf("\n--- Wyniki konwersji ---\n");
    printf("%.2f cm to:\n", centimeters);
    printf("- %.2f cali\n", inches);
    printf("- %.2f stop\n", feet);
}

// --- ZADANIE 3: Pole i obwód koła ---
// Program oblicza pole i obwód koła na podstawie promienia
// podanego przez użytkownika.
void task03(void) {
    // Deklaracja zmiennych typu double.
    double radius, area, circumference;

    // Prośba o podanie promienia.
    printf("\nPodaj promien kola: ");
    // Wczytanie wartości promienia od użytkownika.
    scanf("%lf", &radius);

    // Sprawdzenie, czy promień jest wartością dodatnią.
    if (radius > 0) {
        // Obliczenie pola koła: P = pi * r^2
        // Funkcja pow(podstawa, wykładnik) podnosi liczbę do potęgi.
        // M_PI to stała matematyczna pi z biblioteki math.h.
        area = M_PI * pow(radius, 2);

        // Obliczenie obwodu koła: L = 2 * pi * r
        circumference = 2 * M_PI * radius;

        // Wyświetlenie wyników z dokładnością do dwóch miejsc po przecinku.
        printf("\n--- Wyniki ---\n");
        printf("Pole kola: %.2f\n", area);
        printf("Obwod kola: %.2f\n", circumference);
    } else {
        // Informacja o błędnych danych (promień musi być dodatni).
        printf("Promien musi byc liczba dodatnia!\n");
    }
}

// --- ZADANIE 4: Kalkulator BMI ---
// Program oblicza wskaźnik masy ciała (BMI) na podstawie
// wagi (kg) i wzrostu (m) podanych przez użytkownika.
void task04(void) {
    // Deklaracja zmiennych typu float.
    float weight_kg, height_m, bmi;

    // Pobranie danych od użytkownika - waga.
    printf("\nPodaj swoja wage w kilogramach: ");
    // Wczytanie wartości wagi. Specyfikator "%f" jest używany dla typu float.
    scanf("%f", &weight_kg);

    // Pobranie danych od użytkownika - wzrost w metrach.
    printf("Podaj swoj wzrost w metrach (np. 1.75): ");
    // Wczytanie wartości wzrostu.
    scanf("%f", &height_m);

    // Sprawdzenie, czy podane dane są prawidłowe (większe od zera).
    if (weight_kg > 0 && height_m > 0) {
        // Obliczenie BMI według wzoru: waga / (wzrost * wzrost)
        // BMI = masa ciała w kg / (wzrost w metrach)^2
        bmi = weight_kg / (height_m * height_m);

        // Wyświetlenie wyniku z dokładnością do jednego miejsca po przecinku.
        printf("\nTwoj wskaznik BMI wynosi: %.1f\n", bmi);
    } else {
        // Informacja o błędnych danych.
        printf("Waga i wzrost musza byc wartosciami dodatnimi!\n");
    }
}

// --- MENU GŁÓWNE ---
// Funkcja wyświetlająca menu główne programu.
void displayMenu(void) {
    // Wyświetlenie wizualnie oddzielonego menu z opcjami.
    printf("\n=================================\n");
    printf("        MENU GLOWNE\n");
    printf("=================================\n");
    printf("1. Operacje arytmetyczne\n");
    printf("2. Konwersja centymetrow\n");
    printf("3. Pole i obwod kola\n");
    printf("4. Kalkulator BMI\n");
    printf("0. Wyjscie\n");
    printf("=================================\n");
    printf("Wybierz opcje: ");
}

// --- FUNKCJA GŁÓWNA ---
int main(void) {
    // Zmienna przechowująca wybór użytkownika z menu.
    int choice;

    // Pętla główna programu - działa dopóki użytkownik nie wybierze opcji "0" (wyjście).
    do {
        // Wyświetlenie menu.
        displayMenu();
        // Wczytanie wyboru użytkownika.
        scanf("%d", &choice);

        // Instrukcja switch obsługująca różne opcje menu.
        switch (choice) {
            case 1:
                // Wywołanie zadania 1 - operacje arytmetyczne.
                task01();
                break;
            case 2:
                // Wywołanie zadania 2 - konwersja centymetrów.
                task02();
                break;
            case 3:
                // Wywołanie zadania 3 - pole i obwód koła.
                task03();
                break;
            case 4:
                // Wywołanie zadania 4 - kalkulator BMI.
                task04();
                break;
            case 0:
                // Zakończenie programu - wyświetlenie komunikatu pożegnalnego.
                printf("\nDo zobaczenia!\n");
                break;
            default:
                // Obsługa nieprawidłowego wyboru.
                printf("\nNieprawidlowa opcja. Sprobuj ponownie.\n");
        }
    } while (choice != 0);  // Kontynuuj pętlę, dopóki użytkownik nie wybierze 0.

    // Zakończenie programu z kodem sukcesu.
    return 0;
}