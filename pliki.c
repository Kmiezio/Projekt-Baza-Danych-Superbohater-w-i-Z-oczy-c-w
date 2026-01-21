#include <stdio.h>
#include <stdlib.h>
#include "pliki.h"

int zapisz_do_pliku(const Lista *lista, const char *nazwa_pliku) {
    FILE *f = fopen(nazwa_pliku, "wb");
    if (!f) {
        printf("Blad: nie mozna otworzyc pliku do zapisu.\n");
        return 0;
    }

    Wezel *tmp = lista->head;
    while (tmp) {
        fwrite(&tmp->dane, sizeof(Postac), 1, f);
        tmp = tmp->next;
    }

    fclose(f);
    return 1;
}

int wczytaj_z_pliku(Lista *lista, const char *nazwa_pliku) {
    FILE *f = fopen(nazwa_pliku, "r");
    if (!f) {
        printf("Brak pliku danych – start z pusta baza.\n");
        return 0;
    }

    char linia[512];
    Postac p;
    int rola, status;

    while (fgets(linia, sizeof(linia), f)) {
        if (sscanf(linia, " %99[^;];%d;%99[^;];%d;%99[^;];%d",
            p.pseudonim,
            &rola,
            p.moc,
            &p.poziom_zagrozenia,
            p.dzielnica,
            &status
        ) == 6) {

            p.rola = (Rola)rola;
            p.status = (Status)status;
            dodaj_postac(lista, p);
        }
    }

    fclose(f);
    return 1;
}

