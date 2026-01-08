#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "lista.h"
#include "postac.h"
#include "pliki.h"

int main(void) {
    Lista lista;
    inicjalizuj_liste(&lista);

    int wybor;
    wczytaj_z_pliku(&lista, "baza.dat");

    do {
        wyswietl_menu();
        wybor = pobierz_wybor();

        switch (wybor) {

        case 1: {
            Postac p = utworz_postac();
            dodaj_postac(&lista, p);
            break;
        }

        case 2: {
            char pseudonim[MAX_TXT];
            printf("Pseudonim do edycji: ");
            fgets(pseudonim, MAX_TXT, stdin);
            pseudonim[strcspn(pseudonim, "\n")] = 0;

            Postac *p = znajdz_postac(&lista, pseudonim);
            if (p) {
                edytuj_postac(p);
                printf("Postac edytowana.\n");
            } else {
                printf("Nie znaleziono postaci.\n");
            }
            break;
        }

        case 3: {
            char pseudonim[MAX_TXT];
            printf("Pseudonim do usuniecia: ");
            fgets(pseudonim, MAX_TXT, stdin);
            pseudonim[strcspn(pseudonim, "\n")] = 0;

            if (usun_postac(&lista, pseudonim))
                printf("Postac usunieta.\n");
            else
                printf("Nie znaleziono postaci.\n");
            break;
        }
        case 4: {
    char pseudonim[MAX_TXT];
    printf("Pseudonim do wyszukania: ");
    fgets(pseudonim, MAX_TXT, stdin);
    pseudonim[strcspn(pseudonim, "\n")] = 0;

    Postac *p = znajdz_postac(&lista, pseudonim);
    if (p) {
        printf("\n--- ZNALEZIONA POSTAC ---\n");
        printf("Pseudonim: %s\n", p->pseudonim);
        printf("Rola: %d\n", p->rola);
        printf("Moc: %s\n", p->moc);
        printf("Poziom zagrozenia: %d\n", p->poziom_zagrozenia);
        printf("Dzielnica: %s\n", p->dzielnica);
        printf("Status: %d\n", p->status);
    } else {
        printf("Nie znaleziono postaci.\n");
    }
    break;
}


        case 5:
            wyswietl_liste(&lista);
            break;

            case 6:
    sortuj_po_zagrozeniu(&lista);
    printf("Posortowano po poziomie zagrozenia.\n");
    break;

        case 0:
            printf("Zamykanie programu...\n");
            break;

        default:
            printf("Niepoprawny wybor.\n");
        }

    } while (wybor != 0);

    zapisz_do_pliku(&lista, "baza.dat");

    zwolnij_liste(&lista);
    return 0;
}
