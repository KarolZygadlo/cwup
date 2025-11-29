#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h> // Dla system()
#include <time.h>   // Zachowane dla spójności

#define BASE 2
#define LOW_LIMIT -5
#define HIGH_LIMIT 20

void task01(void) {
    int n;
    long long suma = 0;
    int i = 1;

    printf("Podaj dodatnia liczbe calkowita N: ");
    int scanf_result = scanf("%d", &n);

    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    while (i <= n) {
        suma += (long long)i * i;
        i++;
    }

    printf("Suma kwadratow od 1 do %d wynosi: %lld\n", n, suma);
}

void task02(void) {
    int liczba;
    int scanf_result;

    do {
        printf("Podaj liczbe z przedzialu 1-100: ");
        scanf_result = scanf("%d", &liczba);

        if (scanf_result != 1) {
            while (getchar() != '\n');
            printf("Nieprawidlowe dane. Sprobuj ponownie.\n");
            continue;
        }

        if (liczba < 1 || liczba > 100) {
            printf("Bledna wartosc. Sprobuj ponownie.\n");
        }

    } while (scanf_result != 1 || liczba < 1 || liczba > 100);

    printf("Wprowadzono poprawna liczbe: %d.\n", liczba);
}

void task03(void) {
    int n;
    printf("Podaj liczbe N do tabliczki mnozenia: ");
    int scanf_result = scanf("%d", &n);

    if (scanf_result != 1) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane!\n");
        return;
    }

    printf("Tabliczka mnozenia dla %d:\n", n);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}

void task04(void) {
    int m, n;
    int scanf_result;

    do {
        printf("Podaj dolny zakres m (min %d): ", LOW_LIMIT);
        scanf_result = scanf("%d", &m);
        if (scanf_result != 1) {
            while (getchar() != '\n');
            printf("Nieprawidlowe dane.\n");
            continue;
        }

        printf("Podaj gorny zakres n (max %d): ", HIGH_LIMIT);
        scanf_result = scanf("%d", &n);
        if (scanf_result != 1) {
            while (getchar() != '\n');
            printf("Nieprawidlowe dane.\n");
            continue;
        }

        if (m < LOW_LIMIT) {
            printf("Blad: m jest ponizej %d.\n", LOW_LIMIT);
        } else if (n > HIGH_LIMIT) {
            printf("Blad: n jest powyzej %d.\n", HIGH_LIMIT);
        } else if (n < m) {
            printf("Blad: n nie moze byc mniejsze niz m.\n");
        }

    } while (m < LOW_LIMIT || n > HIGH_LIMIT || n < m);

    printf("\nPotegi %d^m ... %d^n\n", BASE, BASE);

    printf("\n--- Wersja WHILE ---\n");
    int i = m;
    while (i <= n) {
        printf("%d^%d = %.4f\n", BASE, i, pow(BASE, (double)i));
        i++;
    }

    printf("\n--- Wersja DO...WHILE ---\n");
    int j = m;
    do {
        printf("%d^%d = %.4f\n", BASE, j, pow(BASE, (double)j));
        j++;
    } while (j <= n);

    printf("\n--- Wersja FOR ---\n");
    for (int k = m; k <= n; k++) {
        printf("%d^%d = %.4f\n", BASE, k, pow(BASE, (double)k));
    }
}

void task05(void) {
    int h;
    printf("Podaj wysokosc trojkata h: ");
    int scanf_result = scanf("%d", &h);

    if (scanf_result != 1 || h <= 0) {
        if (scanf_result != 1) {
             while (getchar() != '\n');
        }
        printf("Nieprawidlowe dane! Podaj dodatnia liczbe calkowita.\n");
        return;
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void displayMenu(void) {
    printf("\n=================================\n");
    printf("      MENU GLOWNE (Lista 07)\n");
    printf("=================================\n");
    printf("1. Suma kwadratow (while)\n");
    printf("2. Walidacja (do...while)\n");
    printf("3. Tabliczka mnozenia (for)\n");
    printf("4. Potegowanie (3 petle)\n");
    printf("5. Rysuj trojkat (nested for)\n");
    printf("0. Wyjscie\n");
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