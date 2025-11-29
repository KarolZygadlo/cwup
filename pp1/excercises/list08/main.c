#include <stdio.h>
#include <stdlib.h> // Dla rand(), srand(), system()
#include <time.h>   // Dla time()
#include <math.h>   // Dla M_PI

#define N_ROT 10    // Stała dla zadania 3
#define LOTTO_SIZE 6 // Stała dla zadania 5

/*
 * ROZWIĄZANIE DLA ZADANIA 1 (Lista 08)
 * Szereg Leibniza (pętla for, precyzja)
 */
void task01(void) {
    int n;
    int scanf_result;
    double pi_approx = 0.0;
    double znak = 1.0;

    printf("Obliczanie przyblizenie liczby PI (Szereg Leibniza).\n");
    printf("Podaj liczbe wyrazow szeregu (n): ");
    scanf_result = scanf("%d", &n);

    if (scanf_result != 1 || n <= 0) {
        while (getchar() != '\n');
        printf("Nieprawidlowe dane! Podaj dodatnia liczbe calkowita.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        double mianownik = 2.0 * i + 1.0;
        pi_approx += znak * (1.0 / mianownik);
        znak = -1.0 * znak;
    }

    pi_approx = pi_approx * 4.0;

    printf("\nWyniki dla n = %d:\n", n);
    printf("Obliczone PI: %.15f\n", pi_approx);
    printf("Stala M_PI:   %.15f\n", M_PI);
    printf("Roznica:      %.15f\n", fabs(M_PI - pi_approx));
}

/*
 * ROZWIĄZANIE DLA ZADANIA 2 (Lista 08)
 * Instrukcje break i continue (Sumator)
 */
void task02(void) {
    int liczba;
    int suma = 0;
    int scanf_result;

    printf("Sumator warunkowy.\n");
    printf("Podaj liczby calkowite.\n");
    printf(" - Liczba ujemna: zostanie pominieta.\n");
    printf(" - Zero (0): konczy wprowadzanie i wyswietla wynik.\n\n");

    while (1) {
        printf("Podaj liczbe: ");
        scanf_result = scanf("%d", &liczba);

        if (scanf_result != 1) {
            while (getchar() != '\n');
            printf("To nie jest liczba! Sprobuj ponownie.\n");
            continue;
        }

        if (liczba == 0) {
            break;
        }

        if (liczba < 0) {
            printf("Liczby ujemne sa ignorowane!\n");
            continue;
        }

        suma += liczba;
    }

    printf("\nKoniec wprowadzania.\nSuma liczb dodatnich wynosi: %d\n", suma);
}

/*
 * ROZWIĄZANIE DLA ZADANIA 3 (Lista 08)
 * Tablice jednowymiarowe - Rotacja cykliczna
 */
void task03(void) {
    int tab[N_ROT];

    printf("Tablica przed przesunieciem:\n");
    for (int i = 0; i < N_ROT; i++) {
        tab[i] = rand() % 100; // Zakres 0-99
        printf("%d ", tab[i]);
    }
    printf("\n");

    int ostatni = tab[N_ROT - 1];

    for (int i = N_ROT - 1; i > 0; i--) {
        tab[i] = tab[i - 1];
    }

    tab[0] = ostatni;

    printf("Tablica po przesunieciu w prawo:\n");
    for (int i = 0; i < N_ROT; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

/*
 * ROZWIĄZANIE DLA ZADANIA 4 (Lista 08)
 * Statystyka tablicowa
 */
void task04(void) {
    double tab[10] = {4.5, 2.0, 3.5, 8.0, 1.0, 5.5, 9.0, 2.0, 6.5, 7.0};
    int rozmiar = 10;

    double suma = 0.0;
    double minVal = tab[0];
    double maxVal = tab[0];

    printf("Elementy tablicy: ");
    for(int i=0; i<rozmiar; i++) {
        printf("%.1f ", tab[i]);

        suma += tab[i];

        if (tab[i] < minVal) minVal = tab[i];
        if (tab[i] > maxVal) maxVal = tab[i];
    }
    printf("\n");

    double srednia = suma / rozmiar;

    int licznik = 0;
    for(int i=0; i<rozmiar; i++) {
        if (tab[i] > srednia) {
            licznik++;
        }
    }

    printf("\n--- Statystyki ---\n");
    printf("Srednia arytmetyczna: %.2f\n", srednia);
    printf("Minimum: %.2f\n", minVal);
    printf("Maksimum: %.2f\n", maxVal);
    printf("Ilosc elementow > srednia: %d\n", licznik);
}

/*
 * ROZWIĄZANIE DLA ZADANIA 5 (Lista 08)
 * Symulator LOTTO (Petle zagniezdzone, unikalnosc)
 */
void task05(void) {
    int userNumbers[LOTTO_SIZE];
    int lottoNumbers[LOTTO_SIZE];
    int scanf_result;

    printf("--- SYMULATOR LOTTO ---\n");
    printf("Wybierz 6 unikalnych liczb z zakresu 1-49.\n");

    for (int i = 0; i < LOTTO_SIZE; i++) {
        int temp;
        int unikalna;

        do {
            unikalna = 1;
            printf("Podaj liczbe nr %d: ", i + 1);
            scanf_result = scanf("%d", &temp);

            if (scanf_result != 1) {
                while (getchar() != '\n');
                printf("To nie liczba!\n");
                unikalna = 0;
                continue;
            }

            if (temp < 1 || temp > 49) {
                printf("Liczba spoza zakresu 1-49!\n");
                unikalna = 0;
            }
            else {
                for (int j = 0; j < i; j++) {
                    if (userNumbers[j] == temp) {
                        printf("Ta liczba juz zostala wybrana!\n");
                        unikalna = 0;
                        break;
                    }
                }
            }

        } while (unikalna == 0);

        userNumbers[i] = temp;
    }

    for (int i = 0; i < LOTTO_SIZE; i++) {
        int temp;
        int unikalna;

        do {
            unikalna = 1;
            temp = rand() % 49 + 1; // 1-49

            for (int j = 0; j < i; j++) {
                if (lottoNumbers[j] == temp) {
                    unikalna = 0;
                    break;
                }
            }
        } while (unikalna == 0);

        lottoNumbers[i] = temp;
    }

    for(int i=0; i<LOTTO_SIZE-1; i++)
        for(int j=0; j<LOTTO_SIZE-1-i; j++)
            if(userNumbers[j] > userNumbers[j+1]) {
                int swp = userNumbers[j]; userNumbers[j] = userNumbers[j+1]; userNumbers[j+1] = swp;
            }
    for(int i=0; i<LOTTO_SIZE-1; i++)
        for(int j=0; j<LOTTO_SIZE-1-i; j++)
            if(lottoNumbers[j] > lottoNumbers[j+1]) {
                int swp = lottoNumbers[j]; lottoNumbers[j] = lottoNumbers[j+1]; lottoNumbers[j+1] = swp;
            }

    printf("\nTwoje liczby:   ");
    for (int i = 0; i < LOTTO_SIZE; i++) printf("%d ", userNumbers[i]);

    printf("\nWynik losowania:");
    for (int i = 0; i < LOTTO_SIZE; i++) printf("%d ", lottoNumbers[i]);

    // KROK 3: Sprawdzenie trafien
    int trafienia = 0;
    for (int i = 0; i < LOTTO_SIZE; i++) {
        for (int j = 0; j < LOTTO_SIZE; j++) {
            if (userNumbers[i] == lottoNumbers[j]) {
                trafienia++;
            }
        }
    }

    printf("\n\nLiczba trafien: %d\n", trafienia);
    if (trafienia == 6) printf("GRATULACJE! SZOSTKA!\n");
    else if (trafienia >= 3) printf("Brawo! Wygrana pieniezna.\n");
    else printf("Niestety, sprobuj nastepnym razem.\n");
}

/*
 * FUNKCJE POMOCNICZE I MAIN
 */

void displayMenu(void) {
    printf("\n=================================\n");
    printf("      LISTA ZADAN 08\n");
    printf("=================================\n");
    printf(" 1. Szereg Leibniza (Zad. 1)\n");
    printf(" 2. Sumator (break/continue) (Zad. 2)\n");
    printf(" 3. Rotacja Tablicy (Zad. 3)\n");
    printf(" 4. Statystyka Tablicowa (Zad. 4)\n");
    printf(" 5. Symulator LOTTO (Zad. 5)\n");
    printf(" 0. Wyjscie\n");
    printf("=================================\n");
    printf("Wybierz opcje: ");
}

int main(void) {
    system("chcp 65001 >nul");

    srand((unsigned int)time(NULL));

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
        while (getchar() != '\n') {}

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
                printf("\nKoniec programu.\n");
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