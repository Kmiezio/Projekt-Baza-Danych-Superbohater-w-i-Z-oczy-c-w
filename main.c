#include <stdio.h>
#include "menu.h"
#include "lista.h"
#include "postac.h"

int main(void) {
    Lista lista;
    inicjalizuj_liste(&lista);
    int wybor;

    do {
        wyswietl_menu();
        wybor = pobierz_wybor();

        switch (wybor) {
            case 1: {
                Postac p = utworz_postac();
                dodaj_postac(&lista, p);
                break;
            }

            case 5: {
                wyswietl_liste(&lista);
                break;
            }

            case 0:
                printf("Zamykanie programu...\n");
                break;

            default:
                printf("Niepoprawny wybor.\n");
                break;
        }

    } while (wybor != 0);

    zwolnij_liste(&lista);
    return 0;
}
