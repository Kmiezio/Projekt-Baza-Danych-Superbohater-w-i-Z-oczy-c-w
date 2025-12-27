//Plik odpowiada za interakcję z użytkownikiem.
//Wyświetla menu tekstowe, pobiera wybory użytkownika 
// i wywołuje odpowiednie funkcje logiki programu.
#include <stdio.h>
#include "menu.h"

void wyswietl_menu(void) {
    printf("\n");
    printf("+---------------------------+\n");
    printf("|        MENU GLOWNE        |\n");
    printf("+---------------------------+\n");
    printf("| 1. Dodaj postac           |\n");
    printf("| 2. Edytuj postac          |\n");
    printf("| 3. Usun postac            |\n");
    printf("| 4. Wyszukaj               |\n");
    printf("| 5. Wyswietl wszystkie     |\n");
    printf("| 0. Wyjscie                |\n");
    printf("+---------------------------+\n");
    printf("Wybor: ");
}

int pobierz_wybor(void) {
    int wybor;
    scanf("%d", &wybor);
    return wybor;
}

