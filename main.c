#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "lista.h"
#include "postac.h"
#include "pliki.h"

int main(int argc, char *argv[]) {
    const char *plik;

    if (argc < 2) {
        printf("Uzycie: %s <plik_danych>\n", argv[0]);
        return 1;
    }

    plik = argv[1];

    Lista lista;
    inicjalizuj_liste(&lista);

    wczytaj_z_pliku(&lista, plik);


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
    int opcja;
    char tekst[MAX_TXT];
    int liczba;

    printf("1. Po pseudonimie (prefiks)\n");
    printf("2. Po dzielnicy\n");
    printf("3. Po poziomie zagrozenia >=\n");
    printf("Wybor: ");
    scanf("%d", &opcja);
    getchar();

    switch (opcja) {
        case 1:
            printf("Podaj prefiks pseudonimu: ");
            fgets(tekst, MAX_TXT, stdin);
            tekst[strcspn(tekst, "\n")] = 0;
            wyszukaj_po_pseudonimie(&lista, tekst);
            break;

        case 2:
            printf("Podaj dzielnice: ");
            fgets(tekst, MAX_TXT, stdin);
            tekst[strcspn(tekst, "\n")] = 0;
            wyszukaj_po_dzielnicy(&lista, tekst);
            break;

        case 3:
            printf("Podaj minimalny poziom zagrozenia: ");
            scanf("%d", &liczba);
            getchar();
            wyszukaj_po_zagrozeniu(&lista, liczba);
            break;

        default:
            printf("Niepoprawna opcja.\n");
    }
    break;
}



        case 5:
            wyswietl_liste(&lista);
            break;


            case 6:
    sortuj_po_pseudonimie(&lista);
    printf("Posortowano alfabetycznie po pseudonimie.\n");
    break;


    
        case 0:
            printf("Zamykanie programu...\n");
            break;

        default:
            printf("Niepoprawny wybor.\n");
        }

    } while (wybor != 0);

     zapisz_do_pliku(&lista, plik);
    zwolnij_liste(&lista);
    return 0;
}
