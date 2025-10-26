#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/*
 * ROZWIĄZANIE DLA ZADANIA 1
 * Minimalny program w C z komentarzami opisującymi jego strukturę.
 */
void task01(void) {
    printf("Witaj Swiecie!\n");
}

/*
 * ROZWIĄZANIE DLA ZADANIA 2
 * Program demonstruje:
 * 1. Zjawisko przepełnienia (overflow) dla typu `unsigned char`.
 * 2. Użycie typu logicznego `bool` z biblioteki <stdbool.h>.
 */
void task02(void) {
    puts("--- Demonstracja przepełnienia (overflow) ---");
    unsigned char test_val = 255;
    printf("Maksymalna wartosc dla unsigned char: %u\n", test_val);
    test_val = test_val + 1;
    printf("Wartosc po dodaniu 1 (przepełnienie): %u\n\n", test_val);

    puts("--- Demonstracja typu bool ---");
    bool isStudent = true;
    bool isFinished = false;
    printf("Wartosc logiczna 'true' jako liczba: %u\n", isStudent);
    printf("Wartosc logiczna 'false' jako liczba: %u\n", isFinished);
}

/*
 * ROZWIĄZANIE DLA ZADANIA 3
 * Program oblicza długość przeciwprostokątnej trójkąta prostokątnego
 * na podstawie twierdzenia Pitagorasa.
 */
void task03(void) {
    double a, b, c;
    int scanf_result;

    printf("Podaj dlugosc przyprostokatnej a: ");
    scanf_result = scanf("%lf", &a);

    // Sprawdzenie poprawności wczytania i czyszczenie bufora.
    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane! Wprowadz liczbe.\n");
        return;
    }

    printf("Podaj dlugosc przyprostokatnej b: ");
    scanf_result = scanf("%lf", &b);

    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane! Wprowadz liczbe.\n");
        return;
    }

    if (a > 0 && b > 0) {
        c = sqrt(pow(a, 2) + pow(b, 2));
        printf("\nDlugosc przeciwprostokatnej c wynosi: %.2f\n", c);
    } else {
        printf("\nDlugosci bokow musza byc dodatnie!\n");
    }
}

/*
 * ROZWIĄZANIE DLA ZADANIA 4
 * Program konwertuje temperaturę podaną w stopniach Celsjusza
 * na stopnie Fahrenheita i Kelwina.
 */
void task04(void) {
    double celsius, fahrenheit, kelvin;
    int scanf_result;

    printf("Podaj temperature w stopniach Celsjusza: ");
    scanf_result = scanf("%lf", &celsius);

    // Zabezpieczenie przed niepoprawnym wejściem.
    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane! Wprowadz liczbe.\n");
        return;
    }

    fahrenheit = (celsius * 9.0 / 5.0) + 32;
    kelvin = celsius + 273.15;

    printf("\n--- Wyniki konwersji ---\n");
    printf("%.2f st. C to:\n", celsius);
    printf("- %.2f st. Fahrenheita\n", fahrenheit);
    printf("- %.2f Kelwinow\n", kelvin);
}

/*
 * ROZWIĄZANIE DLA ZADANIA 5
 * Program wczytuje małą literę, konwertuje ją na dużą
 * i wyświetla jej kod w tabeli ASCII.
 */
void task05(void) {
    char lower_char, upper_char;

    printf("Podaj jedna mala litere: ");
    scanf(" %c", &lower_char);

    if (lower_char >= 'a' && lower_char <= 'z') {
        upper_char = lower_char - 32;
        printf("\nWprowadzony znak: %c\n", lower_char);
        printf("Jego kod ASCII: %d\n", lower_char);
        printf("Duza litera: %c\n", upper_char);
        printf("Kod ASCII duzej litery: %d\n", upper_char);
    } else {
        printf("Wprowadzono niepoprawny znak (nie jest to mala litera).\n");
    }
}

/*
 * ROZWIĄZANIE DLA ZADANIA 6
 * Program oblicza pierwiastki równania kwadratowego ax^2 + bx + c = 0.
 */
void task06(void) {
    double a, b, c, delta, x1, x2;
    int scanf_result;

    puts("--- Kalkulator rownania kwadratowego ax^2 + bx + c = 0 ---");

    printf("Podaj wspolczynnik a: ");
    scanf_result = scanf("%lf", &a);
    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane! Wprowadz liczbe.\n");
        return;
    }

    printf("Podaj wspolczynnik b: ");
    scanf_result = scanf("%lf", &b);
    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane! Wprowadz liczbe.\n");
        return;
    }

    printf("Podaj wspolczynnik c: ");
    scanf_result = scanf("%lf", &c);
    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane! Wprowadz liczbe.\n");
        return;
    }

    if (a == 0) {
        printf("To nie jest rownanie kwadratowe (a=0).\n");
        return;
    }

    delta = pow(b, 2) - 4 * a * c;
    printf("\nDelta wynosi: %.2f\n", delta);

    if (delta > 0) {
        x1 = (-b - sqrt(delta)) / (2 * a);
        x2 = (-b + sqrt(delta)) / (2 * a);
        printf("Rownanie ma dwa pierwiastki rzeczywiste:\n");
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    } else if (delta == 0) {
        x1 = -b / (2 * a);
        printf("Rownanie ma jeden pierwiastek rzeczywisty:\n");
        printf("x0 = %.2f\n", x1);
    } else {
        printf("Rownanie nie ma pierwiastkow rzeczywistych.\n");
    }
}

void displayMenu(void) {
    printf("\n=================================\n");
    printf("        MENU GLOWNE\n");
    printf("=================================\n");
    printf("1. Witaj Swiecie\n");
    printf("2. Overflow i bool\n");
    printf("3. Twierdzenie Pitagorasa\n");
    printf("4. Konwersja temperatur\n");
    printf("5. Konwersja ASCII\n");
    printf("6. Rownanie kwadratowe\n");
    printf("0. Wyjscie\n");
    printf("=================================\n");
    printf("Wybierz opcje: ");
}

int main(void) {
    int choice;
    int scanf_result;

    do {
        displayMenu();
        scanf_result = scanf("%d", &choice);

        // Zabezpieczenie menu przed niepoprawnym wejściem.
        if (scanf_result != 1) {
            while (getchar() != '\n');
            printf("\nNieprawidlowe dane! Wprowadz liczbe.\n");
            continue;
        }

        switch (choice) {
            case 1:
                task01();
                break;
            case 2:
                task02();
                break;
            case 3:
                task03();
                break;
            case 4:
                task04();
                break;
            case 5:
                task05();
                break;
            case 6:
                task06();
                break;
            case 0:
                printf("\nDo zobaczenia!\n");
                break;
            default:
                printf("\nNieprawidlowa opcja. Sprobuj ponownie.\n");
        }
    } while (choice != 0);

    return 0;
}
