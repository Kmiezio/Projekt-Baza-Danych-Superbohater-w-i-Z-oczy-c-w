#ifndef LISTA_H
#define LISTA_H

#include "postac.h"

typedef struct Wezel {
    Postac dane;
    struct Wezel *next;
} Wezel;

typedef struct {
    Wezel *head;
} Lista;

void inicjalizuj_liste(Lista *lista);
void dodaj_postac(Lista *lista, Postac p);
void wyswietl_liste(const Lista *lista);
void zwolnij_liste(Lista *lista);
void sortuj_po_zagrozeniu(Lista *lista);
void wyszukaj_po_pseudonimie(const Lista *lista, const char *prefiks);
void wyszukaj_po_dzielnicy(const Lista *lista, const char *dzielnica);
void wyszukaj_po_zagrozeniu(const Lista *lista, int poziom);
void sortuj_po_pseudonimie(Lista *lista);



Postac* znajdz_postac(Lista *lista, const char *pseudonim);
int usun_postac(Lista *lista, const char *pseudonim);

#endif

