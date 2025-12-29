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
        }

    } while (wybor != 0);

    return 0;
}
