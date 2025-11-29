#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h> // Dla ran1d(), srand() i system()
#include <time.h>   // Dla time()

/*
 * ROZWIĄZANIE DLA ZADANIA 1.1
 */
void task01(void) {
    double a, b, c;
    printf("Podaj dlugosci bokow a, b, c (oddzielone spacja): ");
    int scanf_result = scanf("%lf %lf %lf", &a, &b, &c);

    if (scanf_result != 3) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    if (a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a)) {
        printf("Z podanych bokow mozna zbudowac trojkat.\n");
    } else {
        printf("Z podanych bokow nie mozna zbudowac trojkata.\n");
    }
}

/*
 * ROZWIĄZANIE DLA ZADANIA 1.2
 */
void task02(void) {
    double a, b, c;
    printf("Podaj dlugosci bokow a, b, c (oddzielone spacja): ");
    int scanf_result = scanf("%lf %lf %lf", &a, &b, &c);

    if (scanf_result != 3) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    if (a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a)) {
        printf("Z podanych bokow mozna zbudowac trojkat.\n");
        double s = (a + b + c) / 2.0;
        double pole = sqrt(s * (s - a) * (s - b) * (s - c));
        printf("Pole tego trojkata (wzor Herona): %.2f\n", pole);
    } else {
        printf("Z podanych bokow nie mozna zbudowac trojkata.\n");
    }
}

/*
 * ROZWIĄZANIE DLA ZADANIA 1.3
 */
void task03(void) {
    float a, b, c, d, e, f;
    float W, Wx, Wy;
    int scanf_result;

    printf("Rownanie 1 (ax + by = c)\nPodaj a, b, c: ");
    scanf_result = scanf("%f %f %f", &a, &b, &c);
    if (scanf_result != 3) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    printf("Rownanie 2 (dx + ey = f)\nPodaj d, e, f: ");
    scanf_result = scanf("%f %f %f", &d, &e, &f);
    if (scanf_result != 3) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    W = a * e - b * d;
    Wx = c * e - b * f;
    Wy = a * f - c * d;

    if (W != 0) {
        float x = Wx / W;
        float y = Wy / W;
        printf("Uklad oznaczony. Rozwiazanie:\n");
        printf("x = %.3f\n", x);
        printf("y = %.3f\n", y);
    } else if (Wx == 0 && Wy == 0) {
        printf("Uklad nieoznaczony (nieskonczenie wiele rozwiazan).\n");
    } else {
        printf("Uklad sprzeczny (brak rozwiazan).\n");
    }
}

/*
 * ROZWIĄZANIE DLA ZADANIA 1.5
 */
void task04(void) {
    int liczba, wynik;
    printf("Podaj liczbe calkowita: ");
    int scanf_result = scanf("%d", &liczba);

    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    wynik = (liczba < 0) ? -liczba : liczba;
    printf("Wartosc bezwzgledna z %d to %d.\n", liczba, wynik);
}

/*
 * ROZWIĄZANIE DLA ZADANIA 2.1
 */
void task05(void) {
    enum dzien { PN, WT, SR, CZW, PT, SOB, NIEDZ };
    enum dzien wolny;

    srand(time(NULL));
    wolny = rand() % 7;

    printf("Wylosowany numer dnia: %u\n", wolny);

    switch (wolny) {
        case PN:
            printf("poniedzialek\n");
            break;
        case WT:
            printf("wtorek\n");
            break;
        case SR:
            printf("sroda\n");
            break;
        case CZW:
            printf("czwartek\n");
            break;
        case PT:
            printf("piatek\n");
            break;
        case SOB:
            printf("sobota\n");
            break;
        case NIEDZ:
            printf("niedziela\n");
            break;
    }
}

/*
 * ROZWIĄZANIE DLA ZADANIA 2.2
 */
void task06(void) {
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

    printf("Podaj operator (+, -, *, /): ");
    scanf_result = scanf(" %c", &operator);
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

    switch (operator) {
        case '+':
            wynik = a + b;
            printf("Wynik: %.2f + %.2f = %.2f\n", a, b, wynik);
            break;
        case '-':
            wynik = a - b;
            printf("Wynik: %.2f - %.2f = %.2f\n", a, b, wynik);
            break;
        case '*':
            wynik = a * b;
            printf("Wynik: %.2f * %.2f = %.2f\n", a, b, wynik);
            break;
        case '/':
            if (b == 0) {
                printf("Blad: Dzielenie przez zero!\n");
            } else {
                wynik = a / b;
                printf("Wynik: %.2f / %.2f = %.2f\n", a, b, wynik);
            }
            break;
        default:
            printf("Nieznany operator: %c\n", operator);
    }
}

/*
 * ROZWIĄZANIE DLA ZADANIA 2.3
 */
void task07(void) {
    int dzien;
    printf("Podaj numer dnia tygodnia (1-7): ");
    int scanf_result = scanf("%d", &dzien);

    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    switch (dzien) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("Dzien roboczy.\n");
            break;
        case 6:
        case 7:
            printf("Dzien wolny (weekend).\n");
            break;
        default:
            printf("Bledny numer dnia.\n");
    }
}

/*
 * ROZWIĄZANIE DLA ZADANIA 2.4
 */
void task08(void) {
    int predkosc;
    printf("Podaj predkosc wiatru w km/h: ");
    int scanf_result = scanf("%d", &predkosc);

    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    if (predkosc < 0) {
        printf("Predkosc nie moze byc ujemna.\n");
        return;
    }

    printf("Opis: ");
    switch (predkosc) {
        case 0 ... 1:
            printf("Cisza.\nStan morza: Gladkie.\n");
            break;
        case 2 ... 5:
            printf("Powiew.\nStan morza: Drobne zmarszczki.\n");
            break;
        case 6 ... 11:
            printf("Slaby wiatr.\nStan morza: Male falki.\n");
            break;
        case 12 ... 19:
            printf("Lagodny wiatr.\nStan morza: Duze falki.\n");
            break;
        case 20 ... 28:
            printf("Umiarkowany wiatr.\nStan morza: Pieniste grzywacze.\n");
            break;
        case 29 ... 38:
            printf("Dosyc silny wiatr.\nStan morza: Gesiejawy.\n");
            break;
        case 39 ... 49:
            printf("Silny wiatr.\nStan morza: Wysokie fale.\n");
            break;
        case 50 ... 61:
            printf("Bardzo silny wiatr (sztorm).\nStan morza: Bardzo wysokie fale.\n");
            break;
        default:
            printf("Huragan.\nStan morza: Wyjatkowo wzburzone.\n");
    }
}

/*
 * ROZWIĄZANIE DLA ZADANIA 2.5
 */
void task09(void) {
    const char* miesiace[] = {
        "Styczen", "Luty", "Marzec", "Kwiecien", "Maj", "Czerwiec",
        "Lipiec", "Sierpien", "Wrzesien", "Pazdziernik", "Listopad", "Grudzien"
    };

    int n;
    printf("Podaj numer miesiaca (1-12): ");
    int scanf_result = scanf("%d", &n);

    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    if (n >= 1 && n <= 12) {
        printf("Miesiac nr %d to %s.\n", n, miesiace[n - 1]);
    } else {
        printf("Bledny numer miesiaca.\n");
    }
}

/*
 * ROZWIĄZANIE DLA ZADANIA 3.1
 */
void task10(void) {
    double x1, y1, x2, y2, x3, y3;
    double a, b, c;
    int scanf_result;

    printf("Podaj wspolrzedne P1 (x1 y1): ");
    scanf_result = scanf("%lf %lf", &x1, &y1);
    if (scanf_result != 2) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    printf("Podaj wspolrzedne P2 (x2 y2): ");
    scanf_result = scanf("%lf %lf", &x2, &y2);
    if (scanf_result != 2) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    printf("Podaj wspolrzedne P3 (x3 y3): ");
    scanf_result = scanf("%lf %lf", &x3, &y3);
    if (scanf_result != 2) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    printf("Obliczone boki: a=%.2f, b=%.2f, c=%.2f\n", a, b, c);

    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        printf("Z podanych punktow mozna zbudowac trojkat.\n");
        double s = (a + b + c) / 2.0;
        double pole = sqrt(s * (s - a) * (s - b) * (s - c));
        printf("Pole tego trojkata (wzor Herona): %.2f\n", pole);
    } else {
        printf("Z podanych punktow nie mozna zbudowac trojkata (punkty sa wspoliniowe).\n");
    }
}

/*
 * ROZWIĄZANIE DLA ZADANIA 3.2
 */
void task11(void) {
    int wyborDrzwi;
    int scanf_result;

    printf("Stoisz w ciemnym korytarzu. Widzisz troje drzwi:\n");
    printf("(1) Czerwone, (2) Zielone, (3) Niebieskie.\n");
    printf("Ktore wybierasz? (1, 2, 3): ");

    scanf_result = scanf("%d", &wyborDrzwi);
    if (scanf_result != 1) {
        while (getchar() != '\n');
        wyborDrzwi = 0;
    } else {
         while (getchar() != '\n');
    }

    switch (wyborDrzwi) {
        case 1: {
            char decyzja;
            printf("Pokoj jest goracy. Na srodku stoi skrzynia. Czy otwierasz? (t/n): ");
            scanf_result = scanf(" %c", &decyzja);
            while (getchar() != '\n');

            if (decyzja == 't' || decyzja == 'T') {
                printf("W srodku jest zloto! Wygrales!\n");
            } else {
                printf("Uniknales pulapki. Wracasz na korytarz. Koniec gry.\n");
            }
            break;
        }
        case 2: {
            int zagadka;
            printf("Trafiasz do ogrodu. Spotykasz medrca.\n");
            printf("'Odpowiedz na zagadke: Co ma klucze, ale nie otwiera zamkow?'\n");
            printf("(1) Fortepian, (2) Mapa: ");
            scanf_result = scanf("%d", &zagadka);
             if (scanf_result != 1) {
                while (getchar() != '\n');
                zagadka = 0;
            } else {
                while (getchar() != '\n');
            }

            if (zagadka == 1) {
                printf("Dobra odpowiedz! Medrzec daje Ci klucz. Wygrales!\n");
            } else {
                printf("Zla odpowiedz. Medrzec Cie wygania. Koniec gry.\n");
            }
            break;
        }
        case 3: {
            char dzwignia;
            printf("Drzwi zatrzaskuja sie za Toba. Pokoj jest pusty, poza mala dzwignia.\n");
            printf("Czy ja pociagasz? (t/n): ");
            scanf_result = scanf(" %c", &dzwignia);
            while (getchar() != '\n');

            if (dzwignia == 't' || dzwignia == 'T') {
                printf("Otwiera sie zapadnia! Spadasz w ciemnosc. Przegrales.\n");
            } else {
                printf("Stoisz w miejscu, az gasnie swiatlo. Przegrales.\n");
            }
            break;
        }
        default:
            printf("Potykasz sie w ciemnosci i wracasz na poczatek. Koniec gry.\n");
    }
}

void displayMenu(void) {
    printf("\n=================================\n");
    printf("      MENU GLOWNE (Lista 06)\n");
    printf("=================================\n");
    printf(" 1. Warunek Trojkata (1.1)\n");
    printf(" 2. Pole Herona (1.2)\n");
    printf(" 3. Uklad Rownan (1.3)\n");
    printf(" 4. Wartosc Bezwzgledna (1.5)\n");
    printf(" 5. Dzien Tygodnia (2.1)\n");
    printf(" 6. Kalkulator Switch (2.2)\n");
    printf(" 7. Grupowanie Case (2.3)\n");
    printf(" 8. Skala Beauforta (2.4)\n");
    printf(" 9. Miesiace (2.5)\n");
    printf("10. Pole (Wspolrzedne) (3.1)\n");
    printf("11. Gra Labirynt (3.2)\n");
    printf(" 0. Wyjscie\n");
    printf("=================================\n");
    printf("Wybierz opcje: ");
}

int main(void) {
    system("chcp 65001 >nul");

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

        if (choice != 0) {
            printf("\n--- Rozwiazanie zadania %d ---\n", choice);
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
            case 7:
                task07();
                break;
            case 8:
                task08();
                break;
            case 9:
                task09();
                break;
            case 10:
                task10();
                break;
            case 11:
                task11();
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