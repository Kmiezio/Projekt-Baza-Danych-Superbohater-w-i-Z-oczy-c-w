#include <stdio.h>
#include <stdlib.h>
#include "pliki.h"

int zapisz_do_pliku(const Lista *lista, const char *nazwa) {
    FILE *f = fopen(nazwa, "wb");
    if (!f) return 0;

    Wezel *tmp = lista->head;
    while (tmp) {
        fwrite(&tmp->dane, sizeof(Postac), 1, f);
        tmp = tmp->next;
    }

    fclose(f);
    return 1;
}

int wczytaj_z_pliku(Lista *lista, const char *nazwa) {
    FILE *f = fopen(nazwa, "rb");
    if (!f) return 0;

    Postac p;
    while (fread(&p, sizeof(Postac), 1, f) == 1) {
        dodaj_postac(lista, p);
    }

    fclose(f);
    return 1;
}
