//Plik zawiera funkcję main, będącą punktem startowym programu.
// Odpowiada za uruchomienie menu głównego oraz zakończenie programu.
#include <stdio.h>
#include "menu.h"

int main(void) {
    int wybor;

    do {
        wyswietl_menu();
        wybor = pobierz_wybor();

        printf("Wybrales opcje: %d\n", wybor);

    } while (wybor != 0);

    printf("Koniec programu.\n");
    return 0;
}

