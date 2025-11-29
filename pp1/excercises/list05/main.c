#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void task01(void) {
    int wiek;
    int scanf_result;

    printf("Podaj swoj wiek: ");
    scanf_result = scanf("%d", &wiek);

    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane! Wprowadz liczbe calkowita.\n");
        return;
    }

    if (wiek >= 18) {
        printf("Jestes pelnoletni/a.\n");
    } else {
        printf("Nie jestes jeszcze pelnoletni/a.\n");
    }
}

void task02(void) {
    int liczba;
    int scanf_result;

    printf("Podaj liczbe calkowita: ");
    scanf_result = scanf("%d", &liczba);

    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane! Wprowadz liczbe calkowita.\n");
        return;
    }

    if (liczba > 0) {
        printf("Liczba jest dodatnia.\n");
    } else if (liczba < 0) {
        printf("Liczba jest ujemna.\n");
    } else {
        printf("Liczba to zero.\n");
    }
}

void task03(void) {
    int rok;
    int scanf_result;

    printf("Podaj rok: ");
    scanf_result = scanf("%d", &rok);

    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane! Wprowadz liczbe calkowita.\n");
        return;
    }

    if ((rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0)) {
        printf("Rok %d jest przestepny.\n", rok);
    } else {
        printf("Rok %d nie jest przestepny.\n", rok);
    }
}

void task04(void) {
    double a, b, wynik;
    char operator;
    int scanf_result;

    printf("Podaj pierwsza liczbe (double): ");
    scanf_result = scanf("%lf", &a);
    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    printf("Podaj druga liczbe (double): ");
    scanf_result = scanf("%lf", &b);
    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    printf("Podaj operator (+, -, *, /): ");
    scanf_result = scanf(" %c", &operator);
    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    if (operator == '+') {
        wynik = a + b;
        printf("Wynik: %.2f + %.2f = %.2f\n", a, b, wynik);
    } else if (operator == '-') {
        wynik = a - b;
        printf("Wynik: %.2f - %.2f = %.2f\n", a, b, wynik);
    } else if (operator == '*') {
        wynik = a * b;
        printf("Wynik: %.2f * %.2f = %.2f\n", a, b, wynik);
    } else if (operator == '/') {
        if (b == 0) {
            printf("Blad: Dzielenie przez zero!\n");
        } else {
            wynik = a / b;
            printf("Wynik: %.2f / %.2f = %.2f\n", a, b, wynik);
        }
    } else {
        printf("Nieznany operator: %c\n", operator);
    }
}

void task05(void) {
    int wybor1, wybor2, wybor3;
    int scanf_result;

    printf("Stoisz na rozdrozu w ciemnym lesie. Mozesz isc w (1) lewo lub (2) prawo.\n");
    printf("Ktora sciezke wybierasz? (wpisz 1 lub 2): ");

    scanf_result = scanf("%d", &wybor1);

    if (scanf_result != 1) {
        while (getchar() != '\n');
        wybor1 = 0;
    } else {
        while (getchar() != '\n');
    }


    if (wybor1 == 1) {
        printf("Idac w lewo, docierasz do starej chaty. (1) Wchodzisz do srodka, (2) Omijasz ja.\n");
        printf("Twoj wybor: ");
        scanf_result = scanf("%d", &wybor2);

        if (scanf_result != 1) {
            while (getchar() != '\n');
            wybor2 = 0;
        } else {
             while (getchar() != '\n');
        }

        if (wybor2 == 1) {
            printf("W srodku znajdujesz skrzynie ze skarbem! Wygrales!\n");
        } else {
            printf("Omijajac chate, gubisz sie w lesie. Koniec gry.\n");
        }

    } else if (wybor1 == 2) {
        printf("Idac w prawo, spotykasz niedzwiedzia. (1) Uciekasz, (2) Probujesz walczyc.\n");
        printf("Twoj wybor: ");
        scanf_result = scanf("%d", &wybor3);

        if (scanf_result != 1) {
            while (getchar() != '\n');
            wybor3 = 0;
        } else {
            while (getchar() != '\n');
        }

        if (wybor3 == 1) {
            printf("Udalo Ci sie uciec. Jestes bezpieczny. Koniec gry.\n");
        } else {
            printf("Niedzwiedz byl zbyt silny. Przegrales.\n");
        }
    } else {
        printf("Stoisz w miejscu tak dlugo, ze zapada noc. Zgubiles sie.\n");
    }
}

void task06(void) {
    double a, b, c;
    int scanf_result;

    printf("Podaj dlugosc boku a: ");
    scanf_result = scanf("%lf", &a);
    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    printf("Podaj dlugosc boku b: ");
    scanf_result = scanf("%lf", &b);
    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    printf("Podaj dlugosc boku c: ");
    scanf_result = scanf("%lf", &c);
    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Dlugosci bokow musza byc dodatnie.\n");
        return;
    }

    if ((a + b > c) && (a + c > b) && (b + c > a)) {

        if (a == b && b == c) {
            printf("Trojkat rownoboczny.\n");
        } else if (a == b || a == c || b == c) {
            printf("Trojkat rownoramienny.\n");
        } else {
            printf("Trojkat roznoboczny.\n");
        }

    } else {
        printf("Z tych bokow nie mozna zbudowac trojkata.\n");
    }
}

void displayMenu(void) {
    printf("\n=================================\n");
    printf("      MENU GLOWNE (Lista 05)\n");
    printf("=================================\n");
    printf("1. Sprawdzanie pelnoletnosci\n");
    printf("2. Klasyfikacja liczby\n");
    printf("3. Rok przestepny\n");
    printf("4. Prosty kalkulator\n");
    printf("5. Gra \"Rozdroza\"\n");
    printf("6. Klasyfikacja trojkata\n");
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

        if (scanf_result != 1) {
            while (getchar() != '\n');
            printf("\nNieprawidlowe dane! Wprowadz liczbe.\n");
            continue;
        }
        while (getchar() != '\n');

        printf("\n--- Rozwiazanie zadania %d ---\n", choice);
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

        if (choice != 0) {
             printf("\nNacisnij Enter, aby wrocic do menu...");
             while (getchar() != '\n');
        }

    } while (choice != 0);

    return 0;
}