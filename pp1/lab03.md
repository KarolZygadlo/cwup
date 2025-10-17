## Lista 03 - Podstawy programowania w C

### Zadanie 1 - Typy całkowite w C 

W środowisku CLion zdefiniuj projekt, a następnie przeanalizuj i uruchom Przykład 1 z wykładu nr 3. Kod ten demonstruje, jak wyświetlić rozmiary i zakresy różnych typów całkowitych w języku C.

```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> /* deklaracje stałych typów całkowitych */

int main(int argc, char* argv[]) {
    fflush(stdout);
    system("chcp 65001 > NUL");
    system("gcc --version");

    puts("Rozmiary (w bajtach) typów całkowitych, C17, x64)");
    printf("char\t\t%d\n", sizeof(char));
    printf("short\t\t%d\n", sizeof(short));
    printf("int\t\t%d\n", sizeof(int));
    printf("unsigned int\t%d\n", sizeof(unsigned int));
    printf("long\t\t%d\n", sizeof(long));
    printf("long long\t%llu\n", sizeof(long long));
    printf("unsigned long long\t%llu\n\n", sizeof(unsigned long long));

    puts("\nZakresy wybranych typów całkowitych, C17, x64)");
    puts("uwaga na specyfikatory formatu!\n");
    printf("short int\t\t%hd\t\t%hd\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short int\t%hu\t\t%hu\n", 0, USHRT_MAX);
    printf("int\t\t\t%d\t\t%d\n", INT_MIN, INT_MAX);
    printf("unsigned int\t\t%u\t\t%u\n", 0, UINT_MAX);
    printf("long int\t\t%ld\t\t%ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long int\t%lu\t\t%lu\n", 0, ULONG_MAX);
    printf("long long int\t\t%lld\t%lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long int\t%llu\t\t%llu\n\n", 0, ULLONG_MAX);

    system("pause");
    return 0;
}
```

### Zadanie 2 - Typy zmiennoprzecinkowe w C

W tym samym projekcie przeanalizuj i uruchom Przykład 2 z wykładu nr 3. Kod ten prezentuje właściwości typów zmiennoprzecinkowych (`float`, `double`, `long double`).

```c
#include <stdio.h>
#include <stdlib.h>
#include <float.h> /* deklaracje stałych typów binarnych zmp */

int main(int argc, char* argv[]) {
    fflush(stdout);
    system("chcp 65001 >NUL");
    system("gcc --version");

    puts("\nRozmiary (w bitach) typów zmp, C17, x64)");
    printf("float\t\t%d\n", sizeof(float)*8);
    printf("double\t\t%d\n", sizeof(double)*8);
    printf("long double\t%d\n\n", sizeof(long double)*8);

    puts("\nCharakterystyka typu float");
    printf("min\t\t%e\n", FLT_MIN);
    printf("max\t\t%e\n", FLT_MAX);
    printf("precyzja (10)\t%d\n", FLT_DIG);
    float myFloat = 3.141592653589f;
    printf("Fixed-point notation (%%f): %f\n", myFloat);
    printf("Scientific notation (%%e): %e\n\n", myFloat);

    puts("\nCharakterystyka typu double");
    printf("min\t\t%.2e\n", DBL_MIN);
    printf("max\t\t%.2e\n", DBL_MAX);
    printf("precyzja (10)\t%d\n", DBL_DIG);
    double myDouble = 3.141592653589;
    printf("Fixed-point notation (%%lf): %lf\n", myDouble);
    printf("Scientific notation (%%le): %le\n\n", myDouble);

    puts("\nCharakterystyka typu long double");
    printf("min\t\t%.2Le\n", LDBL_MIN);
    printf("max\t\t%.2Le\n", LDBL_MAX);
    printf("precyzja (10)\t%d\n", LDBL_DIG);
    long double myLongDouble = 3.141592653589L;
    printf("Fixed-point notation (%%Lf): %Lf\n", myLongDouble);
    printf("Scientific notation (%%Le): %Le\n\n", myLongDouble);
    
    system("pause");
    return 0;
}
```

### Zadanie 3 - Modyfikacja typów danych

Uruchom Przykład 2 z wykładu nr 2. Następnie zmodyfikuj go tak, aby zamiast operacji na zmiennych typu int wykonywał je na zmiennych typu int64_t, a zamiast typu float używał long double.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    fflush(stdout);
    fflush(stdin);
    system("chcp 65001 > NUL");
    // UTF-8
    int arg1, arg2, iadd, isub, imul, idiv, imod;
    puts("Operacje arytmetyczne na liczbach typu 'int'");
    printf("Podaj dwie liczby typu int oddzielone spacją: ");
    fflush(stdin);
    // usuń znaki z bufora klawiatury
    scanf("%d%d", &arg1, &arg2);
    iadd = arg1 + arg2;
    printf("%d %c %d = %d\n", arg1, '+',arg2, iadd);
    isub = arg1 - arg2;
    printf("%d %c %d = %d\n", arg1, '-',arg2, isub);
    imul = arg1 * arg2;
    printf("%d %c %d = %d\n", arg1, '*',arg2, imul);
    if (arg2 != 0) // warunek wykonania operacji
    {
        idiv = arg1 / arg2;
        printf("%d %c %d = %d\n", arg1, '/',arg2, idiv);
        imod = arg1 % arg2;
        printf("%d %c %d = %d\n", arg1, '%',arg2, imod);
    }
    float farg1, farg2, fadd, fsub, fmul, fdiv;
    puts("\nOperacje arytmetyczne na liczbach typu 'float'");
    printf("Podaj dwie liczby typu float oddzielone spacją: ");
    fflush(stdin);
    // usuń znaki z bufora klawiatury
    scanf("%f%f", &farg1, &farg2);
    fadd = farg1 + farg2;
    printf("%.3f + %.3f = %f\n", farg1, farg2, fadd);
    fsub = farg1 - farg2;
    printf("%.3f - %.3f = %f\n", farg1, farg2, fsub);
    fmul = farg1 * farg2;
    printf("%.3f * %.3f = %f\n", farg1, farg2, fmul);
    fdiv = farg1 / farg2;
    printf("%.3f / %.3f = %f\n\n", farg1, farg2, fdiv);
    system("pause");
    return 0;
}
```

### Zadanie 4: Konwerter jednostek
Napisz od podstaw prosty program, który przelicza jednostki długości. Program powinien prosić użytkownika o podanie wartości w centymetrach, a następnie przeliczyć ją na cale i stopy. 

Wymagania:

- Do wczytania danych od użytkownika użyj funkcji `scanf()`. 

- Zastosuj typ `double` do przechowywania wartości, aby zapewnić dokładność.

- Wyniki wyświetl na ekranie z opisem.

- Przyjmij, że: `1 cal = 2.54 cm`, `1 stopa = 12 cali`.


### Zadanie 5: Obliczanie pola i obwodu koła

Napisz program, który prosi użytkownika o podanie promienia koła, a następnie oblicza i wyświetla jego pole oraz obwód.

Wymagania:

- Dołącz bibliotekę `<math.h>`, aby uzyskać dostęp do stałej `M_PI`.

- Użyj typu double dla wszystkich zmiennych zmiennoprzecinkowych.

- Wzory do obliczeń:

  - Pole: $P = \pi \cdot r^2$

  - Obwód: $L = 2 \cdot \pi \cdot r$

- Wyniki wyświetl z dokładnością do dwóch miejsc po przecinku (użyj `%.2f`).

### Zadanie 6: Prosty kalkulator BMI

Stwórz program, który oblicza wskaźnik masy ciała (BMI). Program powinien pobrać od użytkownika wagę w kilogramach oraz wzrost w metrach.

Wymagania:

- Użyj typu `float` do przechowywania danych.

- Wzór na BMI: $BMI = \frac{waga}{wzrost^2}$

- Wyświetl obliczony wskaźnik BMI.