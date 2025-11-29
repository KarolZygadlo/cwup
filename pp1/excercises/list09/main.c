#include <stdio.h>
#include <stdlib.h> // system(), abs()
#include <math.h>   // sqrt()
#include <stdbool.h> // bool, true, false

/* Stale dla zadania 4 (Macierze) */
#define M_ROWS 3
#define N_COLS 4

/* Stale dla zadania 5 (Kolko i krzyzyk) */
#define BOARD_SZ 3

/* * ============================================
 * ROZWIĄZANIE DLA ZADANIA 1 (Lista 09)
 * Funkcje i Wskazniki - Rownanie Kwadratowe
 * ============================================
 */

/* Funkcja obliczajaca pierwiastki. Zwraca ilosc rozwiazan.
   Wyniki zapisuje pod adresami x1 i x2 (przekazywanie przez wskaznik). */
int solveQuadratic(double a, double b, double c, double *x1, double *x2) {
    if (a == 0) {
        // To nie jest rownanie kwadratowe (przypadek liniowy bx + c = 0)
        return -1;
    }

    double delta = (b * b) - (4 * a * c);

    if (delta > 0) {
        *x1 = (-b - sqrt(delta)) / (2 * a);
        *x2 = (-b + sqrt(delta)) / (2 * a);
        return 2;
    } else if (delta == 0) {
        *x1 = -b / (2 * a);
        return 1;
    } else {
        return 0;
    }
}

void task01(void) {
    double a, b, c;
    double x1, x2;
    int numSolutions;

    printf("--- Rownanie Kwadratowe (ax^2 + bx + c = 0) ---\n");
    printf("Podaj wspolczynniki a, b, c: ");

    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        while (getchar() != '\n');
        printf("Blad: Podaj liczby rzeczywiste.\n");
        return;
    }

    // Wywolanie funkcji - przekazujemy adresy zmiennych x1 i x2 (&)
    numSolutions = solveQuadratic(a, b, c, &x1, &x2);

    printf("\nWynik:\n");
    switch (numSolutions) {
        case 2:
            printf("Dwa rozwiazania: x1 = %.2f, x2 = %.2f\n", x1, x2);
            break;
        case 1:
            printf("Jedno rozwiazanie: x1 = %.2f\n", x1);
            break;
        case 0:
            printf("Brak rozwiazan w zbiorze liczb rzeczywistych.\n");
            break;
        case -1:
            printf("To nie jest rownanie kwadratowe (a = 0)!\n");
            break;
    }
}

/* * ============================================
 * ROZWIĄZANIE DLA ZADANIA 2 (Lista 09)
 * Rekurencja - Potegowanie Szybkie
 * ============================================
 */

/* Funkcja rekurencyjna obliczajaca base^exponent */
long long power(int base, int exponent) {
    // Przypadek bazowy
    if (exponent == 0) {
        return 1;
    }
    // Krok rekurencyjny
    return base * power(base, exponent - 1);
}

void task02(void) {
    int b, e;

    printf("--- Rekurencyjne Potegowanie ---\n");
    printf("Podaj podstawe (calkowita): ");
    if (scanf("%d", &b) != 1) { while(getchar()!='\n'); return; }

    printf("Podaj wykladnik (nieujemny): ");
    if (scanf("%d", &e) != 1) { while(getchar()!='\n'); return; }

    if (e < 0) {
        printf("Ten prosty przyklad obsluguje tylko wykladniki nieujemne.\n");
        return;
    }

    long long result = power(b, e);
    printf("\nWynik %d^%d = %lld\n", b, e, result);
}

/* * ============================================
 * ROZWIĄZANIE DLA ZADANIA 3 (Lista 09)
 * Funkcje i Tablice - Czy posortowana?
 * ============================================
 */

/* Funkcja sprawdza czy tablica jest posortowana rosnaco.
   Uzywamy const, bo funkcja tylko czyta tablice, nie modyfikuje jej. */
bool isSorted(const int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false; // Znaleziono element wiekszy od nastepnika - blad sortowania
        }
    }
    return true; // Przeszlo cala petle, jest ok
}

void task03(void) {
    int tab1[] = {1, 2, 5, 8, 10};
    int tab2[] = {1, 5, 2, 8, 10};
    int size = 5;

    printf("--- Sprawdzanie posortowania tablic ---\n");

    // Test 1
    printf("Tablica 1: {1, 2, 5, 8, 10} -> ");
    if (isSorted(tab1, size)) printf("POSORTOWANA\n");
    else printf("NIEPOSORTOWANA\n");

    // Test 2
    printf("Tablica 2: {1, 5, 2, 8, 10} -> ");
    if (isSorted(tab2, size)) printf("POSORTOWANA\n");
    else printf("NIEPOSORTOWANA\n");
}

/* * ============================================
 * ROZWIĄZANIE DLA ZADANIA 4 (Lista 09)
 * Tablice 2D - Transpozycja Macierzy
 * ============================================
 */

/* Drukowanie macierzy M x N */
void printMatrix(int rows, int cols, int mat[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        printf("| ");
        for (int j = 0; j < cols; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("|\n");
    }
}

/* Transpozycja: zrodlo (rows x cols) -> cel (cols x rows) */
void transposeMatrix(int rows, int cols, const int src[rows][cols], int dest[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[j][i] = src[i][j]; // Zamiana wierszy z kolumnami
        }
    }
}

void task04(void) {
    // Macierz zrodlowa 3x4
    int matrix[M_ROWS][N_COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Macierz wynikowa 4x3 (wymiary odwrocone)
    int transposed[N_COLS][M_ROWS];

    printf("--- Transpozycja Macierzy ---\n");

    printf("Macierz pierwotna (%dx%d):\n", M_ROWS, N_COLS);
    printMatrix(M_ROWS, N_COLS, matrix);

    // Wykonanie transpozycji
    transposeMatrix(M_ROWS, N_COLS, matrix, transposed);

    printf("\nMacierz transponowana (%dx%d):\n", N_COLS, M_ROWS);
    // Uwaga: tutaj przekazujemy wymiary odwrotnie do funkcji drukujacej
    printMatrix(N_COLS, M_ROWS, transposed);
}

/* * ============================================
 * ROZWIĄZANIE DLA ZADANIA 5 (Lista 09)
 * Gra Konsolowa - "Kółko i Krzyżyk"
 * ============================================
 */

void drawBoard(char b[BOARD_SZ][BOARD_SZ]) {
    // Proste czyszczenie ekranu (dziala na Windows, na Linux uzyj "clear")
    system("cls");

    printf("\n  Kolko i Krzyzyk\n\n");
    printf("   1   2   3\n");
    printf("1  %c | %c | %c \n", b[0][0], b[0][1], b[0][2]);
    printf("  ---+---+---\n");
    printf("2  %c | %c | %c \n", b[1][0], b[1][1], b[1][2]);
    printf("  ---+---+---\n");
    printf("3  %c | %c | %c \n\n", b[2][0], b[2][1], b[2][2]);
}

/* Zwraca 1 jesli ruch udany, 0 jesli pole zajete/blad */
int makeMove(char b[BOARD_SZ][BOARD_SZ], int row, int col, char player) {
    if (row < 0 || row >= BOARD_SZ || col < 0 || col >= BOARD_SZ) return 0;
    if (b[row][col] != ' ') return 0; // Pole zajete

    b[row][col] = player;
    return 1;
}

/* Zwraca 'X', 'O' (wygrana) lub ' ' (gra dalej) */
char checkWin(char b[BOARD_SZ][BOARD_SZ]) {
    // Sprawdzenie wierszy i kolumn
    for (int i = 0; i < BOARD_SZ; i++) {
        if (b[i][0] != ' ' && b[i][0] == b[i][1] && b[i][1] == b[i][2]) return b[i][0];
        if (b[0][i] != ' ' && b[0][i] == b[1][i] && b[1][i] == b[2][i]) return b[0][i];
    }
    // Przekatne
    if (b[0][0] != ' ' && b[0][0] == b[1][1] && b[1][1] == b[2][2]) return b[0][0];
    if (b[0][2] != ' ' && b[0][2] == b[1][1] && b[1][1] == b[2][0]) return b[0][2];

    return ' ';
}

void task05(void) {
    char board[BOARD_SZ][BOARD_SZ];
    // Inicjalizacja spacjami
    for(int i=0; i<BOARD_SZ; i++)
        for(int j=0; j<BOARD_SZ; j++) board[i][j] = ' ';

    char currentPlayer = 'X';
    char winner = ' ';
    int moves = 0;
    int r, c;

    while (winner == ' ' && moves < 9) {
        drawBoard(board);
        printf("Ruch gracza %c.\n", currentPlayer);
        printf("Podaj wiersz i kolumne (1-3 1-3): ");

        if (scanf("%d %d", &r, &c) != 2) {
            while (getchar() != '\n');
            continue;
        }

        // Uzytkownik podaje 1-3, tablica jest 0-2 -> odejmujemy 1
        if (makeMove(board, r - 1, c - 1, currentPlayer)) {
            moves++;
            winner = checkWin(board);
            // Zmiana gracza
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    drawBoard(board);
    if (winner != ' ') {
        printf("GRATULACJE! Wygrywa gracz %c!\n", winner);
    } else {
        printf("REMIS! Plansza pelna.\n");
    }
}

/* * ============================================
 * MENU GLOWNE I MAIN
 * ============================================
 */

void displayMenu(void) {
    printf("\n=================================\n");
    printf("      LISTA ZADAN 09\n");
    printf("=================================\n");
    printf(" 1. Rownanie Kwadratowe (Zad. 1)\n");
    printf(" 2. Rekurencja Potegi (Zad. 2)\n");
    printf(" 3. Czy Posortowana? (Zad. 3)\n");
    printf(" 4. Transpozycja Macierzy (Zad. 4)\n");
    printf(" 5. Gra: Kolko i Krzyzyk (Zad. 5)\n");
    printf(" 0. Wyjscie\n");
    printf("=================================\n");
    printf("Wybierz opcje: ");
}

int main(void) {
    system("chcp 65001 >nul"); // Polskie znaki w konsoli

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
            printf("\n");
        }

        switch (choice) {
            case 1: task01(); break;
            case 2: task02(); break;
            case 3: task03(); break;
            case 4: task04(); break;
            case 5: task05(); break;
            case 0: printf("\nKoniec programu.\n"); break;
            default: printf("\nNieprawidlowa opcja.\n");
        }

        if (choice != 0) {
             printf("\nNacisnij Enter, aby wrocic do menu...");
             while (getchar() != '\n');
        }

    } while (choice != 0);

    return 0;
}