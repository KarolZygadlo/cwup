## Analiza i uruchamianie demonstracyjnych programów w środowisku IDE.

### Agenda
Przewidywany plan zajęć kształtuje się następująco:
* przedstawienie opcji związanych z IDE oraz poruszanie się po nim,
* konto JetBrains i licencja CLion,
* przedstawienie programów demonstracyjnych,
* uruchomienie i analiza programów demonstracyjnych,
* wprowadzenie do systemu kontroli wersji Git oraz środowiska Github,
* inne opcje językowe.

### IDE
* [**CLion**](https://www.jetbrains.com/clion/)
* Dev-Cpp
* Eclipse
* Code::Blocks
* NetBeans
* Visual Studio Code

### Konto JetBrains i licencja CLion
IDE CLion to narzędzie firmy [JetBrains](https://www.jetbrains.com/), ogólnie jest to płatne narzędzie lecz jest opcja aby skorzystać z niego bezpłatnie. 
Należy założyć konto za pomocą adresu e-mail studenckiego na platformie JetBrains - uzyskamy dostęp do dużej ilości darmowych IDE w tym CLion, który jest nam potrzebny.

Proszę wejść na ten [link](https://www.jetbrains.com/shop/eform/students) i załóżyć konto na adres e-mail z domeny uczelnianej (@studenci.collegiumwitelona.pl).
Następnie jeśli na komputerze nie ma IDE CLion proszę je pobrać, i tu mamy dwie opcje:
* pobranie narzędzia [JetBrains Toolbox](https://www.jetbrains.com/lp/toolbox/), a następnie po uruchomieniu z listy aplikacji zainstalować CLion,
* pobranie bezpośrednio [CLion](https://www.jetbrains.com/clion/download).

Przy pierwszym uruchomieniu CLion'a spyta on nas o licencję i wtedy nalezy zalogować się na konto JetBrains, które wcześniej zostało utworzone przez Państwa.
Po zakończeniu pracy/ćwiczeń zalecałbym wylogować się ze swojgo konto (z menu wybieramy **Help** > **Register**, następnie w lewym dolnym rogu będzie widoczne nasze imię i nazwisko - po kliknięciu będziemy mogli się wylogować).

### Programy demonstracyjne w C

* program wypisujący "Hello, World!":

```php
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

* program obliczający pole prostokąta:

```php
#include <stdio.h>

int main() {
    float dlugosc, szerokosc, pole;

    printf("Podaj długość prostokąta: ");
    scanf("%f", &dlugosc);

    printf("Podaj szerokość prostokąta: ");
    scanf("%f", &szerokosc);

    pole = dlugosc * szerokosc;

    printf("Pole prostokąta wynosi: %.2f\n", pole);

    return 0;
}
```

* program sprawdzający, czy podana liczba jest dodatnia, ujemna czy równa zeru:
```php
#include <stdio.h>

int main() {
    int liczba;

    printf("Podaj liczbę całkowitą: ");
    scanf("%d", &liczba);

    if (liczba > 0) {
        printf("Liczba jest dodatnia.\n");
    } else if (liczba < 0) {
        printf("Liczba jest ujemna.\n");
    } else {
        printf("Liczba jest równa zeru.\n");
    }

    return 0;
}
```